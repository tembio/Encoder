#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "encoder.hpp"
#include <sstream>

TEST(Encoder, GetSymbolsReturnsNoSymbolsWhenNoInputHasBeenRead) {
    // Given
    Encoder encoder;

    // When / Then
    EXPECT_EQ (encoder.GetSymbols(), SymbolTable{});
}

TEST(Encoder, GetSymbolsReturnsNoSymbolsWhenEmptyInputHasBeenRead) {
    // Given
    Encoder encoder;

    // When
    std::stringstream{} >> encoder;

    // Then
    EXPECT_EQ (encoder.GetSymbols(), SymbolTable{});
}

TEST(Encoder, GetSymbolsReturnsSymbolsWhenInputHasBeenRead) {
    // Given
    Encoder encoder;
    std::stringstream input;
    input << 'a' << 'b' << 'c';

    // When     
    input >> encoder;

    // Then
    EXPECT_THAT(encoder.GetSymbols(), ::testing::ElementsAre('a','b','c'));
}

TEST(Encoder, GetSymbolsReturnsNonRepeatedSymbolsWhenInputHasBeenRead) {
    // Given
    Encoder encoder;
    std::stringstream input;
    input << 'a' << 'b' << 'b';

    // When     
    input >> encoder;

    // Then
    EXPECT_THAT(encoder.GetSymbols(), ::testing::ElementsAre('a','b'));
}


TEST(Encoder, GetEncodedDataReturnsNoDataWhenNoInputHasBeenRead) {
    // Given
    Encoder encoder;

    // When / Then
    EXPECT_EQ (encoder.GetEncodedData().size(), 0);
}

TEST(Encoder, GetEncodedDataReturnsEncodedDataWhenInputHasBeenRead) {
    // Given
    Encoder encoder;
    std::stringstream input;
    input << "abcac";
    input >> encoder;

    // When 
    std::stringstream output;
    output << encoder.GetEncodedData();

    // Then
    EXPECT_EQ (output.str().c_str()[0], '\x01');
    EXPECT_EQ (output.str().c_str()[1], '\x20');
    EXPECT_EQ (output.str().c_str()[2], '\x02');
}

TEST(Encoder, WriteToOutputIsCorrect) {
    // Given
    Encoder encoder;
    std::stringstream input;
    input << "abcac";
    input >> encoder;

    // When 
    std::stringstream output;
    output << encoder;

    // Then
    EXPECT_EQ (output.str().c_str()[0], 3);
    EXPECT_EQ (output.str().c_str()[1], 'a');
    EXPECT_EQ (output.str().c_str()[2], 'b');
    EXPECT_EQ (output.str().c_str()[3], 'c');
    EXPECT_EQ (output.str().c_str()[4], '\x01');
    EXPECT_EQ (output.str().c_str()[5], '\x20');
    EXPECT_EQ (output.str().c_str()[6], '\x02');
}


TEST(Encoder, WriteToOutputIsCorrectForGivenExample) {
    // Given
    Encoder encoder;
    std::stringstream input;
    input << "RYKARRKAAGCWATYWKMTCTWRAGSRMGCTKGTKCACMYACYTTMG";
    input >> encoder;

    // When 
    std::stringstream output;
    output << encoder;

    // Then
    std::vector<char> expectedChars {
        10,
        'R','Y', 'K', 'A', 'G', 'C', 'W', 'T', 'M', 'S',
        '\x01', '\x23', '\x00', '\x23', '\x34', '\x56', '\x37',
        '\x16', '\x28', '\x75', '\x76', '\x03', '\x49', '\x08',
        '\x45', '\x72', '\x47', '\x25', '\x35', '\x81', '\x35',
        '\x17', '\x78', '\x04'};

    auto index = 0;
    for (auto expected : expectedChars) {
        EXPECT_EQ (output.str().c_str()[index++], expected);
    }    
}
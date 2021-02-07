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
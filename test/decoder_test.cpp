#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "decoder.hpp"
#include <sstream>

TEST(Decoder, GetSymbolsReturnsNoSymbolsWhenNoInputHasBeenRead) {
    // Given
    Decoder decoder;

    // When / Then
    EXPECT_EQ (decoder.GetSymbols(), SymbolTable{});
}

TEST(Decoder, GetSymbolsReturnsNoSymbolsWhenEmptyInputHasBeenRead) {
    // Given
    Decoder decoder;

    // When
    std::stringstream{} >> decoder;

    // Then
    EXPECT_EQ (decoder.GetSymbols(), SymbolTable{});
}

TEST(Decoder, GetSymbolsReturnsSymbolsWhenInputHasBeenRead) {
    // Given
    Decoder decoder;
    std::stringstream input;
    input << (char)3 << 'a' << 'b' << 'c';

    // When     
    input >> decoder;

    // Then
    EXPECT_THAT(decoder.GetSymbols(), ::testing::ElementsAre('a','b','c'));
}

TEST(Decoder, ExceptionIsThrownWhenThereAreMoreThan16Symbols) {
    // Given
    Decoder encoder;
    std::stringstream input;
    input.put(18);

    try {
      // When
      input >> encoder;
      FAIL() << "Expected std::out_of_range";
    }
    catch(std::out_of_range const & err) {
      // Then
      EXPECT_EQ(err.what(),std::string("Number of symbols greater than 16"));
    }
    catch(...) {
      FAIL() << "Expected std::out_of_range";
    }
}

TEST(Decoder, WriteDecodedDataToOutputIsCorrect) {
    // Given
    Decoder decoder;
    std::stringstream input;
    input << (char)3 << 'a' << 'b' << 'c' << char(4) << '\x21' << '\x01';
    input >> decoder;

    // When 
    std::stringstream output;
    output << decoder;

    // Then
    EXPECT_EQ (output.str().c_str()[0], 'c');
    EXPECT_EQ (output.str().c_str()[1], 'b');
    EXPECT_EQ (output.str().c_str()[2], 'a');
    EXPECT_EQ (output.str().c_str()[3], 'b');
}

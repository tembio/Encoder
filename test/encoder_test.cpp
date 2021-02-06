#include "gtest/gtest.h"
#include "encoder.hpp"

TEST(Encoder, GetSymbolsReturnsNoSymbolsIfNoInputHasBeenRead) {
    // Given
    Encoder encoder;

    // When / Then
    EXPECT_EQ (encoder.GetSymbols(), symbolTable{});
}

TEST(Encoder, GetEncodedDataReturnsNoDataIfNoInputHasBeenRead) {
    // Given
    Encoder encoder;

    // When / Then
    EXPECT_EQ (encoder.GetEncodedData(), std::vector<char>{});
}
#include "gtest/gtest.h"
#include "encoder.hpp"

TEST(Encoder, GetSymbolsReturnsNoSymbolsIfNoInputHasBeenRead) {
    // Given
    Encoder encoder;

    // When
    auto symbolTable = encoder.GetSymbolTable();

    // Then
    EXPECT_EQ (symbolTable, std::vector<char>{});
}
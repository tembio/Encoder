#include "gtest/gtest.h"
// #include "gmock/gmock.h"
#include "encodingBuffer.hpp"

TEST(Encoder, SizeReturns0WhenEmptyBuffer) {
    // Given
    EncodingBuffer buffer;

    // When / Then
    EXPECT_EQ (buffer.size(), 0);
}

TEST(Encoder, SizeReturnsCorrectValueAfterAddingData) {
    // Given
    EncodingBuffer buffer;

    // When 
    buffer.push_back(1);
    buffer.push_back(2);
    buffer.push_back(3);

    // Then
    EXPECT_EQ (buffer.size(), 3);
}


TEST(Encoder, IndexingReturnsCorrectDataForOddNumberOfSymbols) {
    // Given
    EncodingBuffer buffer;

    // When 
    buffer.push_back(1);
    // Then
    EXPECT_EQ (buffer[0], 1);

    // When 
    buffer.push_back(2);
    buffer.push_back(3);
    // Then
    EXPECT_EQ (buffer[0], 1);
    EXPECT_EQ (buffer[1], 2);
    EXPECT_EQ (buffer[2], 3);
}

TEST(Encoder, IndexingReturnsCorrectDataForEvenNumberOfSymbols) {
    // Given
    EncodingBuffer buffer;

    // When 
    buffer.push_back(1);
    buffer.push_back(2);
    // Then
    EXPECT_EQ (buffer[0], 1);
    EXPECT_EQ (buffer[1], 2);

    // When 
    buffer.push_back(3);
    buffer.push_back(4);
    // Then
    EXPECT_EQ (buffer[2], 3);
    EXPECT_EQ (buffer[3], 4);
}
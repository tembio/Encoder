#include <sstream>
#include "gtest/gtest.h"
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

TEST(Encoder, IndexingReturnsCorrectData) {
    // Given
    EncodingBuffer buffer;

    // When 
    buffer.push_back(1);
    // Then
    EXPECT_EQ (buffer[0], 1);

    // When 
    buffer.push_back(2);
    // Then
    EXPECT_EQ (buffer[0], 1);
    EXPECT_EQ (buffer[1], 2);

    // When 
    buffer.push_back(3);
    // Then
    EXPECT_EQ (buffer[0], 1);
    EXPECT_EQ (buffer[1], 2);
    EXPECT_EQ (buffer[2], 3);
}

TEST(Encoder, IndexingOutOfBOundsThrowsExceptions) {
    // Given
    EncodingBuffer buffer;
    buffer.push_back(1);

    try {
      // When
      buffer[1];
      FAIL() << "Expected std::out_of_range";
    }
    catch(std::out_of_range const & err) {
      // Then
      EXPECT_EQ(err.what(),std::string("Out of range"));
    }
    catch(...) {
      FAIL() << "Expected std::out_of_range";
    }
}

TEST(Encoder, EncodedDataIsDisplayedInOutput) {
    // Given
    EncodingBuffer buffer;
    buffer.push_back(4);
    buffer.push_back(2);
    buffer.push_back(4);
    buffer.push_back(1);

    // When 
    std::stringstream stream;
    stream<<buffer;
    // Then
    ASSERT_STREQ (stream.str().c_str(), "BA");

    
    // Given
    buffer.push_back(5);
 
    // When 
    std::stringstream stream2;
    stream2<<buffer;
    // Then
    ASSERT_STREQ (stream2.str().c_str(), "BA\x05");
}
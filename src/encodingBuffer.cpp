#include "encodingBuffer.hpp"


EncodingBuffer::EncodingBuffer() {
    size_ = 0;
    positionToWriteInByte_ = PositionInByte::least4SignificantBits;
    buffer_.push_back(0);
}

std::size_t EncodingBuffer::size() const {
    return size_;
}

void EncodingBuffer::push_back(const char& value){
    char& byteBuffer = buffer_.back();

    switch (positionToWriteInByte_) { 
        case PositionInByte::least4SignificantBits:
            byteBuffer = value & 0xf;
            byteBuffer <<= 4;
            
            positionToWriteInByte_ = PositionInByte::most4SignificantBits; 
            break;
        case  PositionInByte::most4SignificantBits:
            byteBuffer |= value & 0xf;
            
            buffer_.push_back(0);
            positionToWriteInByte_ = PositionInByte::least4SignificantBits; 
            break;
    }
    size_++;
}

char EncodingBuffer::operator[](std::size_t idx){
    // if(idx >= size) ERROR

    char output = 0;
    if(idx%2 == 0){ // Value in the 4 most significant bits
        return buffer_[idx/2]>>4;
    }

    return buffer_[idx/2] & 0xf; // Value in the 4 least significant bits
}
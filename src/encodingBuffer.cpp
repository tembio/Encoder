#include "encodingBuffer.hpp"


EncodingBuffer::EncodingBuffer() {
    size_ = 0;
    positionToWriteInByte_ = PositionInByte::least4SignificantBits;
}

std::size_t EncodingBuffer::size() const {
    return size_;
}

void EncodingBuffer::push_back(char value) {

    switch (positionToWriteInByte_) { 
        case PositionInByte::least4SignificantBits:
            buffer_.push_back(value & 0xf);
            
            positionToWriteInByte_ = PositionInByte::most4SignificantBits; 
            break;
        case  PositionInByte::most4SignificantBits:
            char& byte = buffer_.back();
            byte <<= 4;
            byte |= value & 0xf;
            
            positionToWriteInByte_ = PositionInByte::least4SignificantBits; 
            break;
    }
    size_++;
}

char EncodingBuffer::operator[](std::size_t idx) const {
    // if(idx >= size) ERROR

    bool valueInMostSignificantBits = idx%2 == 0;
    bool valueInLastChar = idx/2 == buffer_.size()-1;
    bool lastCharIsFullyWritten = size_%2 == 0;

    if (valueInLastChar) {
        if (lastCharIsFullyWritten && valueInMostSignificantBits) {
            return buffer_.back()>>4;
        }
        return buffer_.back() & 0xf;
    } 

    if (valueInMostSignificantBits) {
        return buffer_[idx/2]>>4; 
    }
    return buffer_[idx/2] & 0xf; // Value in the 4 least significant bits
}

std::ostream& operator<<(std::ostream& os, const EncodingBuffer& e) {
    for(auto c : e.buffer_) {
        os<<c;
    }
}


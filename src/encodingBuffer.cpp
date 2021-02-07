#include "encodingBuffer.hpp"

void setFirstValueInByte(char &byte, char value) {
    byte = value & 0xf; // Write first value in 4 less significant bits
}
void setSecondValueInByte(char &byte, char value) {
    byte <<= 4;                     // Shift first value to most significant 4 bits
    byte |= value & 0xf;            // Write second value in 4 less significant bits
}
char getFirstValueInByte(char byte) {
    return byte >> 4;
}
char getSecondValueInByte(char byte) {
    return byte & 0xf; 
}

EncodingBuffer::EncodingBuffer() {
    size_ = 0;
    valueToWriteInByte_ = ValueInByte::firstValue;
}

std::size_t EncodingBuffer::size() const {
    return size_;
}

void EncodingBuffer::push_back(char value) {
    switch (valueToWriteInByte_) { 
        case ValueInByte::firstValue:
            buffer_.push_back(0);
            setFirstValueInByte(buffer_.back(), value);            
            valueToWriteInByte_ = ValueInByte::secondValue; 
            break;
        case  ValueInByte::secondValue:
            setSecondValueInByte(buffer_.back(), value);
            valueToWriteInByte_ = ValueInByte::firstValue; 
            break;
    }
    size_++;
}

char EncodingBuffer::operator[](std::size_t idx) const {
    if (idx >= size_) {
        throw std::out_of_range("Out of range");
    }

    bool valueInMostSignificantBits = idx%2 == 0;
    bool valueInLastBufferPosition = idx/2 == buffer_.size()-1;
    bool lastPositionIsFullyWritten = size_%2 == 0;

    if (valueInLastBufferPosition) {
        char lastBufferItem = buffer_.back();
        if (lastPositionIsFullyWritten && valueInMostSignificantBits) {
            return getFirstValueInByte(lastBufferItem);
        }
        return getSecondValueInByte(lastBufferItem);
    } 

    char bufferItem = buffer_[idx/2];
    return valueInMostSignificantBits ? 
                getFirstValueInByte(bufferItem) : 
                getSecondValueInByte(bufferItem); 
    
}

std::ostream& operator<<(std::ostream& os, const EncodingBuffer& e) {
    for(auto c : e.buffer_) {
        os<<c;
    }
}


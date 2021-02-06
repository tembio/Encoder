#include "encoder.hpp"

const symbolTable& Encoder::GetSymbols() const {
    return symbols_;
}

const encodingBuffer& Encoder::GetEncodedData() const {
    return buffer_;
}


std::ostream& operator<<(std::ostream& os, const Encoder& e)
{
    //os << dt.mo << '/' << dt.da << '/' << dt.yr;
    return os;
}

std::istream& operator>>(std::istream& is, const Encoder& e)
{
    //os << dt.mo << '/' << dt.da << '/' << dt.yr;
    return is;
}

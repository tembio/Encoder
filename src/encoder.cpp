#include "encoder.hpp"

const std::vector<char>& Encoder::GetSymbolTable() const {
    return symbolTable_;
}

std::istream& operator>>(std::istream& is, const Encoder& e)
{
    //os << dt.mo << '/' << dt.da << '/' << dt.yr;
    return is;
}

std::ostream& operator<<(std::ostream& os, const Encoder& e)
{
    //os << dt.mo << '/' << dt.da << '/' << dt.yr;
    return os;
}
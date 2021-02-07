#include <unordered_map>
#include <sstream>
#include "decoder.hpp"

const SymbolTable& Decoder::GetSymbols() const {
    return symbols_;
}

void checkMaxNumDecodingSymbols(std::size_t numSymbols) {
    if (numSymbols > MAX_SYMBOLS) {
            std::stringstream ss;
            ss << "Number of symbols greater than " << (int)MAX_SYMBOLS;
            throw std::out_of_range(ss.str());
        }
}

std::istream& operator>>(std::istream& is, Decoder& e) {
    char numSymbols;
    is.get(numSymbols);
    checkMaxNumDecodingSymbols(numSymbols);

    e.symbols_ = SymbolTable(numSymbols);
    for (auto& symbol : e.symbols_) {
        is.get(symbol);
    }

    char numSymbolsToDecode;
    is.get(numSymbolsToDecode);

    std::vector<char> encodedData;
    char byte;
    while (is.get(byte))
    {
        encodedData.push_back(byte);
    }
    e.buffer_.setEncodedData(numSymbolsToDecode, std::move(encodedData));

    return is;
}

std::ostream& operator<<(std::ostream& os, Decoder& e) {
    for (auto i=0; i<e.buffer_.size(); i++) {
        auto symbolIndex = e.buffer_[i];
        os.put(e.symbols_[symbolIndex]);
    }
    return os;
}
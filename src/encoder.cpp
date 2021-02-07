#include <unordered_map>
#include "encoder.hpp"

const SymbolTable& Encoder::GetSymbols() const {
    return symbols_;
}

const EncodingBuffer& Encoder::GetEncodedData() const {
    return buffer_;
}

std::istream& operator>>(std::istream& is, Encoder& e) {
    std::unordered_map<char,char> symbolToIndex;
    char symbolIndex = 0;

    char symbol;
    while (is.get(symbol)) {
        if (symbolToIndex.find(symbol) == symbolToIndex.end()) {
            symbolToIndex[symbol] = symbolIndex++;
            e.symbols_.push_back(symbol);
        }

        e.buffer_.push_back(symbolToIndex[symbol]);
    }

    return is;
}

std::ostream& operator<<(std::ostream& os, Encoder& e) {
    os.put(e.symbols_.size());
    os.write(e.symbols_.data(), e.symbols_.size());
    return os << e.buffer_;
}

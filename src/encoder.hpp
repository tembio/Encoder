#include <istream>
#include <vector>
#include "encodingBuffer.hpp"

typedef std::vector<char> SymbolTable;

class Encoder {
    private:
        EncodingBuffer buffer_;
        SymbolTable symbols_;

    public:

    const SymbolTable& GetSymbols() const;
    const EncodingBuffer& GetEncodedData() const;

    friend std::istream& operator>>(std::istream& is, Encoder& e);
};

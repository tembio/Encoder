#include <istream>
#include <vector>
#include "encodingBuffer.hpp"

const char MAX_SYMBOLS = 16;

typedef std::vector<char> SymbolTable;

class Decoder {
    private:
        EncodingBuffer buffer_;
        SymbolTable symbols_;

    public:
        const SymbolTable& GetSymbols() const;

        friend std::istream& operator>>(std::istream& is, Decoder& d);
        friend std::ostream& operator<<(std::ostream& os, Decoder& d);
};

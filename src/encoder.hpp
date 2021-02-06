#include <iostream>
#include <vector>

typedef std::vector<char> symbolTable;
typedef std::vector<char> encodingBuffer;

class Encoder {
    private:
        encodingBuffer buffer_;
        symbolTable symbols_;

    public:

    const symbolTable& GetSymbols() const;
    const encodingBuffer& GetEncodedData() const;

    friend std::ostream& operator<<(std::ostream& os, const Encoder& e);
    friend std::istream& operator>>(std::istream& is, const Encoder& e);

};

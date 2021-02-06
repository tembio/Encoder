#include <iostream>
#include <vector>

class Encoder {
    private:
        std::vector<char> encodedBuffer_;
        std::vector<char> symbolTable_;

    public:

    const std::vector<char>& GetSymbolTable() const;

    friend std::istream& operator>>(std::istream& is, const Encoder& e);
    friend std::ostream& operator<<(std::ostream& os, const Encoder& e);

};

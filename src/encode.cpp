#include <iostream>
#include "encoder.hpp"

int main() {

    Encoder encoder;
    std::cin >> encoder;

    auto symbolTable = encoder.GetSymbols();
    std::cout << symbolTable.size();
    for (auto& symbol : symbolTable) {
        std::cout << symbol;
    }

    auto encodedData = encoder.GetEncodedData();
    std::cout << encodedData.size();
    std::cout << encodedData;

    return 0;
}

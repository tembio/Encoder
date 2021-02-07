#include <iostream>
#include "encoder.hpp"

int main() {

    Encoder encoder;

    try {
        std::cin >> encoder;
    } catch (const std::exception& ex) {
        std::cout << "Error encoding data: " << ex.what() << std::endl;
        return 1;
    }

    std::cout << encoder;

    return 0;
}

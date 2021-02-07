#include <iostream>
#include "decoder.hpp"

int main() {

    Decoder decoder;
    
    try {
        std::cin >> decoder;
    } catch (const std::exception& ex) {
        std::cout << "Error decoding data: " << ex.what() << std::endl;
        return 1;
    }

    std::cout << decoder;

    return 0;
}

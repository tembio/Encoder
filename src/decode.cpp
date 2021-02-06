// #include <iostream>

// char* symbol_table;
// char symbol_table_length = 0;

// int main() {
//     symbol_table = new char[1024];
//     std::cin.get(symbol_table_length);
//     std::cin.read(symbol_table, symbol_table_length);

//     char len;
//     std::cin.get(len);

//     for (int i = 0;; i += 2) {
//         char in;
//         std::cin.get(in);
//         if (std::cin.eof())
//             break;
//         if (i == len - 1) {
//             std::cout.put(symbol_table[in & 0xf]);
//         } else {
//             std::cout.put(symbol_table[(in >> 4) & 0xf]);
//             std::cout.put(symbol_table[in & 0xf]);
//         }
//     }
//     return 0;
// }

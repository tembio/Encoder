#include <iostream>

char* symbol_table;
char symbol_table_length = 0;

void scan(char* input, int length) {
    for (int i = 0; i < length; i++) {
        int j;
        for (j = 0; j < symbol_table_length; j++) {
            if (symbol_table[j] == input[i]) {
                break;
            }
        }
        if (j == symbol_table_length) {
            symbol_table[j] = input[i];
            symbol_table_length++;
        }
    }
}

int main() {
    char* input = new char[1024];
    int i;
    for (i = 0;; i++) {
        std::cin.get(input[i]);
        if (std::cin.eof())
            break;
    }

    symbol_table = new char[1024];
    scan(input, i);

    std::cout.put(symbol_table_length);
    std::cout.write(symbol_table, symbol_table_length);

    std::cout.put(i);

    char out = -1;
    for (int j = 0; j < i; j++) {
        int k;
        for (k = 0; k < symbol_table_length; k++) {
            if (symbol_table[k] == input[j]) {
                break;
            }
        }
        if (out == -1) {
            out = k & 0xf;
            if (j == i - 1) {
                std::cout.put(out);
            }
        } else {
            out <<= 4;
            out |= k & 0xf;
            std::cout.put(out);
            out = -1;
        }
    }
    return 0;
}

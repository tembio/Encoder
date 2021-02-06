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

    // READ FROM CIN -> INPUT
    char* input = new char[1024];
    int i; //number of read chars
    for (i = 0;; i++) {
        std::cin.get(input[i]);
        if (std::cin.eof())
            break;
    }

    // CREATE SYMBOL TABLE
    symbol_table = new char[1024];
    scan(input, i);



    //Print number of symbols
    std::cout.put(symbol_table_length);
    //Print table of symbols
    std::cout.write(symbol_table, symbol_table_length);
    //Print number read chars+1
    std::cout.put(i);



    // OUPTUT COMPACT REPRESENTATION
    char out = -1; //Temp var to print stuff (2 symbols per char)

    for (int j = 0; j < i; j++) { // Foreach char read

        // FIND input  in SYMBOL TABLE
        int k; // INDEX IN SYMBOL TABLE
        for (k = 0; k < symbol_table_length; k++) { //if you find it in the symbol table (stop looking)
            if (symbol_table[k] == input[j]) {
                break;
            }
        }


        if (out == -1) {  // Store in less significative?

            out = k & 0xf; // Store the index of the current item in the least significative half of the byte
            if (j == i - 1) {
                std::cout.put(out);
            }

        } else {

            out <<= 4;     // move the prev index to the most significative part of the byte
            out |= k & 0xf; // Store the index of the current item in the least significative half of the byte
            std::cout.put(out);

            out = -1; // set all bits to 1

        }
    }
    return 0;
}

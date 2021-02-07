#include <vector>
#include <ostream>

enum class ValueInByte { firstValue, secondValue };

class EncodingBuffer {
    private:
        std::vector<char> buffer_;
        std::size_t size_;
        ValueInByte valueToWriteInByte_;

    public:
        EncodingBuffer();
        std::size_t size() const;
        void push_back(char decodedValue);      // Encode data and add it to the buffer
        char operator[](std::size_t idx) const; // Access decoded data by index
        void setEncodedData(std::size_t numSymbols, const std::vector<char>&& data);
        
        // Output encoded data
        friend std::ostream& operator<<(std::ostream& os, const EncodingBuffer& e);
};
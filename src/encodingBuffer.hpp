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
        void push_back(char decodedValue);
        char operator[](std::size_t idx) const;
        void setEncodedData(std::size_t numSymbols, const std::vector<char>&& data);
        
        friend std::ostream& operator<<(std::ostream& os, const EncodingBuffer& e);
};
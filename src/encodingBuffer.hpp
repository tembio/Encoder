#include <vector>

enum class PositionInByte { least4SignificantBits, most4SignificantBits };

class EncodingBuffer {
    private:
        std::vector<char> buffer_;
        std::size_t size_;
        PositionInByte positionToWriteInByte_;

    public:
        EncodingBuffer();
        std::size_t size() const;
        void push_back(const char& value);
        char operator[](std::size_t idx);
};
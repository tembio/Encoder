set(BINARY ${CMAKE_PROJECT_NAME})

set(SOURCES
    encodingBuffer.hpp
    encodingBuffer.cpp

    decode.cpp
    decoder.hpp
    decoder.cpp

    encode.cpp
    encoder.hpp
    encoder.cpp
)

add_executable(${BINARY} ${SOURCES})

add_library(${BINARY}lib STATIC ${SOURCES})

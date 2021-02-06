set(BINARY ${CMAKE_PROJECT_NAME})

set(SOURCES
    decode.cpp

    encode.cpp
    encoder.cpp
    encoder.hpp
)

add_executable(${BINARY} ${SOURCES})

add_library(${BINARY}lib STATIC ${SOURCES})

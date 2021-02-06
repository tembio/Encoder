set(BINARY ${CMAKE_PROJECT_NAME})

set(SOURCES
    decode.cpp
    encode.cpp
)

add_executable(${BINARY} ${SOURCES})

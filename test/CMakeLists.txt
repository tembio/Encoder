set(BINARY tests)

set(TEST_SOURCES main.cpp 
                 encodingBuffer_test.cpp
                 encoder_test.cpp
                 decoder_test.cpp)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
add_executable(${BINARY} ${TEST_SOURCES})

add_test(NAME ${BINARY} COMMAND ${BINARY})

target_link_libraries(${BINARY} PUBLIC ${CMAKE_PROJECT_NAME}lib gtest gmock)
cmake_minimum_required(VERSION 3.14)
project(Hadean)

set(CMAKE_CXX_STANDARD 17)
add_definitions(-Wall)

include_directories(src)

add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(lib/googletest)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(encode src/encode.cpp)
target_link_libraries(encode PUBLIC ${CMAKE_PROJECT_NAME}lib)

#add_executable(decode src/decode.cpp)
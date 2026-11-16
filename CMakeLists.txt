cmake_minimum_required(VERSION 3.20)
project(tkga_preview LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

add_library(tkga_packet STATIC sdk/tkga_packet.c)
target_include_directories(tkga_packet PUBLIC sdk)

add_executable(fence_example examples/fence.c)
target_link_libraries(fence_example PRIVATE tkga_packet)

include(CTest)
if(BUILD_TESTING)
    add_executable(packet_test tests/packet_test.c)
    target_link_libraries(packet_test PRIVATE tkga_packet)
    add_test(NAME packet COMMAND packet_test)
    add_test(NAME fence_example COMMAND fence_example)
    set_tests_properties(fence_example PROPERTIES
        PASS_REGULAR_EXPRESSION "03 00 02 00 34 12")
endif()

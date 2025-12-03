cmake_minimum_required (VERSION 3.8)

project("WINtrrt")

file(GLOB SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c)

add_executable(WINtrrt ${SOURCE_FILES})

target_link_libraries(WINtrrt PRIVATE ws2_32)

target_include_directories(WINtrrt PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include 
)

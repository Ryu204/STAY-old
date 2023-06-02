cmake_minimum_required(VERSION 3.10)

project(Stay)

# dependencies
find_package(SFML 2.5 COMPONENTS graphics REQUIRED)
find_package(LDtkLoader 1.2 REQUIRED)
# file
file(GLOB_RECURSE
    SOURCE_CODE
    "*/*.hpp"
    "*/*.cpp"
    "*/*.h"
    "*/*.c")
# link libraries
add_executable(Stay ${SOURCE_CODE})
target_link_libraries(Stay PRIVATE sfml-graphics LDtkLoader)
cmake_minimum_required(VERSION 3.20)

project(raylibtest LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add source files here
add_executable(build
    src/main.cpp
    src/grid/grid.cpp
    src/simulation/simulation.cpp
)

# Include directories if needed
# target_include_directories(build PRIVATE include)

# Link libraries if needed
target_link_libraries(build PRIVATE libraylib.a)

target_compile_options(build PRIVATE -Wall -Wextra -pedantic)

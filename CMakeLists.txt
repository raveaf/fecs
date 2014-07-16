project(fecs)
cmake_minimum_required(VERSION 2.8)
file(GLOB SRC_LIST "headers/*.hpp" "src/*.cpp" "tests/*.hpp" "tests/*.cpp")
add_executable(${PROJECT_NAME} ${SRC_LIST})
ADD_DEFINITIONS(
    -std=c++11
)


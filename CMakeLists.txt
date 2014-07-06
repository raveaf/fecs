project(FECS)
cmake_minimum_required(VERSION 2.8)
file(GLOB SRC_LIST "*.h" "*.cpp")
#file(GLOB SRC_LIST "test/*.h" "test/*.cpp")
add_executable(${PROJECT_NAME} ${SRC_LIST})
ADD_DEFINITIONS(
    -std=c++11
)


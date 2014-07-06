project(FECS)
cmake_minimum_required(VERSION 2.8)
aux_source_directory(. SRC_LIST)
file(GLOB SRC_LIST_2 "*.h" "*.cpp")
file(GLOB SRC_LIST_2 "test/*.h" "test/*.cpp")
add_executable(${PROJECT_NAME} ${SRC_LIST} ${SRC_LIST_2})
ADD_DEFINITIONS(
    -std=c++11
)


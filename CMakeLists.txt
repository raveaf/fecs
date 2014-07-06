project(fecs)
cmake_minimum_required(VERSION 2.8)
file(GLOB SRC_LIST "src/*.hpp" "src/*.cpp" "tests/*.hpp" "tests/*.cpp")
add_executable(${PROJECT_NAME} ${SRC_LIST})
set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)
ADD_DEFINITIONS(
    -std=c++11
)


cmake_minimum_required(VERSION 3.10.2)

project(PROJ VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(PythonLibs 2.7)

add_executable(clustering clustering.cpp)
add_definitions(-DWITHOUT_NUMPY)
# python
target_include_directories(cluster PRIVATE ${PYTHON_INCLUDE_DIRS})
target_link_libraries(cluster ${PYTHON_LIBRARIES})
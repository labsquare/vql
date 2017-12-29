cmake_minimum_required(VERSION 2.8.12)

project(vql)

#find_package(Boost 1.58 REQUIRED)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(${PROJECT_NAME} "main.cpp" "vqlcompiler.cpp")

target_link_libraries(${PROJECT_NAME})

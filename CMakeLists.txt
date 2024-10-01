cmake_minimum_required(VERSION 3.5)

project(StudentsDatabase VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories("headers/")
// 
add_executable(StudentsDatabase main.cpp StudentsDatabase.cpp Date.cpp FileHandler.cpp Student.cpp StudentsGenerator.cpp)

target_include_directories(StudentsDatabase PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

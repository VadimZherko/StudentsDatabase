cmake_minimum_required(VERSION 3.5)
project(Students_Database VERSION 1.0 LANGUAGES CXX)

include_directories(include)

add_library(Date SHARED src/Date.cpp)
add_library(StudentsDatabase SHARED src/StudentsDatabase.cpp)
add_library(Student SHARED src/Student.cpp)
add_library(StudentsGenerator SHARED src/StudentsGenerator.cpp)
add_library(FileHandler SHARED src/FileHandler.cpp)

add_executable(students_database src/main.cpp)

target_link_libraries(students_database Date StudentsDatabase Student StudentsGenerator FileHandler)

# Статическая/динамическая библиотека - в чём разница и что ты используешь. А главное почему именно это?
# Install

install(TARGETS students_database 
        DESTINATION /usr/local/bin)
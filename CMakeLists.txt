cmake_minimum_required(VERSION 3.24)
project(task2)

set(CMAKE_CXX_STANDARD 17)

add_executable(task2 main.cpp Namespace.cpp Namespace.h classes/MyClassForPoly.cpp classes/MyClassForPoly.h classes/MyInterface.cpp classes/MyInterface.h classes/MyClass.cpp classes/MyClass.h Root.cpp Root.h CLI.cpp CLI.h)

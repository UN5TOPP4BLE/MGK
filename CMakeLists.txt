cmake_minimum_required(VERSION 3.21)
project(MGK)

set(CMAKE_CXX_STANDARD 14)

add_executable(MGK
        main.cpp Vector.cpp Vector.h Matrix3n.cpp Matrix3n.h Matrix4x4.cpp Matrix4x4.h)


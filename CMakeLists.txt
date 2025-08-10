cmake_minimum_required(VERSION 3.31)
project(LazyEngine)

set(CMAKE_CXX_STANDARD 20)

add_library(LazyEngine STATIC Engine.cpp
        property/property.cpp
        property/property.h
        property/transform.cpp
        property/transform.h
)

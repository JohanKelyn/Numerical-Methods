cmake_minimum_required(VERSION 3.5)

project(linearsolvers)

add_library(linearsolvers equations_solvers.cpp)

target_include_directories(linearsolvers PUBLIC ${CMAKE_SOURCE_DIR}/../ext/eigen/)


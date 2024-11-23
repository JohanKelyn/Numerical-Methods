cmake_minimum_required(VERSION 3.5)

project(main)

add_executable(${CMAKE_PROJECT_NAME} src/main.cpp)

add_subdirectory(Linear_Solvers)

target_include_directories(${CMAKE_PROJECT_NAME} 
                            PUBLIC ${CMAKE_SOURCE_DIR}/../ext/eigen/
                            PUBLIC ${CMAKE_SOURCE_DIR}/Linear_Solvers/
)
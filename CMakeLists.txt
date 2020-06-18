cmake_minimum_required(VERSION 3.15)
project(lab2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

find_package(LLVM REQUIRED CONFIG)
set(LLVM_LINK_COMPONENTS
        Core
        Support)

add_executable(test
        cgen.cpp
        cgen.h
        parser.tab.cpp
        parser.tab.hpp
        scanner.cpp)

llvm_map_components_to_libnames(llvm_libs ${LLVM_LINK_COMPONENTS})
target_link_libraries(test ${llvm_libs})
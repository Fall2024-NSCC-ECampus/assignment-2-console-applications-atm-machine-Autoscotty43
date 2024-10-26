cmake_minimum_required(VERSION 3.29)
project(JaredScott_atmMachine)

set(CMAKE_CXX_STANDARD 20)

add_executable(JaredScott_atmMachine main.cpp atm.cpp
        atm.h)

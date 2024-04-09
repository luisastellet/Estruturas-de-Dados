cmake_minimum_required(VERSION 3.27)
project(Lista_2 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Lista_2
        Q1.c
        Q2.c
        Q3d.c
        Q3f.c
        Q4.c
        Q5.c
        TABB.c
        TABB.h
        teste_TABB.c)

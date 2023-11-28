cmake_minimum_required(VERSION 3.22.1)

project(animal)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE
        main.cpp
        Herbivore.h
        Carnivore.h
        Animal.h
        Interact.h
        Fox.h
        Rabbit.h
        Moose.h
        Wolf.h
        )

add_executable(animal main.cpp)

cmake_minimum_required(VERSION 3.22)

Project(linked_list)

set(CMAKE_CXX_STANDARD 11)

add_library(doubly_linked_list STATIC)
target_sources(doubly_linked_list.h doubly_linked_list.cpp)

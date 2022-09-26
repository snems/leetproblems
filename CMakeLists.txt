cmake_minimum_required(VERSION 3.22)
project(leetproblems)

set(CMAKE_CXX_STANDARD 14)
include_directories(. Util Problems)

add_executable(leetproblems main.cpp
        Problems/add_two_numbers.cxx
        Problems/add_two_numbers.hxx
        Problems/longest_common_prefix.cxx
        Util/catch.hpp
        Util/ListNode.cxx
        Util/ListNode.hxx 
		Problems/multiply_strings.cxx)

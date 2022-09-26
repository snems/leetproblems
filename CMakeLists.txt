cmake_minimum_required(VERSION 3.22)
project(leetproblems)

set(CMAKE_CXX_STANDARD 14)
include_directories(. Util Problems)

add_executable(leetproblems main.cpp
        Problems/add_two_numbers.cxx
        Problems/add_two_numbers.hxx
        Problems/longest_common_prefix.cxx
		Problems/multiply_strings.cxx
		Problems/remove_nth_node_from_end_of_list.cxx
		Problems/palindrome_linked_list.cxx
        Util/catch.hpp
        Util/ListNode.cxx
        Util/ListNode.hxx
        Problems/odd_even_linked_list.cxx)

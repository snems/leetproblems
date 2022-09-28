cmake_minimum_required(VERSION 3.22)
project(leetproblems)

set(CMAKE_CXX_STANDARD 17)
include_directories(. Util Problems)

file(GLOB SOURCES
		Problems/*.cxx
		Util/*.cxx
		Util/*.hxx
		Util/*.hpp
		main.cxx
		)

add_executable(leetproblems ${SOURCES})

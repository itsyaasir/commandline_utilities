# Makefile for compiling the C++ code

main:
	g++ -o main main.cpp modules/mkdir.cpp modules/mv.cpp modules/touch.cpp modules/rmdir.cpp modules/rm.cpp modules/mvdir.cpp modules/cat.cpp modules/grep.cpp modules/head.cpp modules/tail.cpp modules/pwd.cpp

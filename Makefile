# Makefile for compiling the C++ code

main:
	g++ -o main modules/mkdir.cpp modules/mv.cpp modules/touch.cpp modules/rmdir.cpp modules/rm.cpp modules/mvdir.cpp 

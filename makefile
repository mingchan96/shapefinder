all: shapefinder

shapefinder: main.o
	g++ main.o -o shapefinder
main.o: main.cpp
	g++ -c main.cpp
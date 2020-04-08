#Makefile for COMP2113_project

lib = lib/
src = src/
inc = include/
FLAG = -pedantic-errors -std=c++11

#//////////////////////////////

$(src)menu.o: $(lib)menu.cpp $(inc)menu.h $(inc)display.h $(inc)main_game.h 
	g++ $(FLAG) -c $< -o $@

$(src)main.o: $(lib)main.cpp $(inc)menu.h
	g++ $(FLAG) -c $< -o $@


#//////////////////////////////

main: $(src)main.o $(src)menu.o
	g++ $(FLAG) $^ -o $@


#//////////////////////////////

run:
	./main

.PHONY: run

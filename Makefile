#Makefile for COMP2113_project

lib = lib/
src = src/
inc = include/
FLAG = -pedantic-errors -std=c++11

#//////////////////////////////

$(src)game_object.o: $(lib)game_object.cpp $(inc)game_object.h 
	g++ $(FLAG) -c $< -o $@

$(src)main_game.o: $(lib)main_game.cpp $(inc)menu.h $(inc)display.h $(inc)game_object.h 
	g++ $(FLAG) -c $< -o $@

$(src)menu.o: $(lib)menu.cpp $(inc)menu.h $(inc)display.h $(inc)main_game.h 
	g++ $(FLAG) -c $< -o $@

$(src)main.o: $(lib)main.cpp $(inc)menu.h 
	g++ $(FLAG) -c $< -o $@


#//////////////////////////////

main: $(src)main.o $(src)menu.o $(src)main_game.o $(src)game_object.o
	g++ $(FLAG) $^ -o $@


#//////////////////////////////

run:
	./main

.PHONY: run

lib = lib/
src = src/
inc = include/
FLAG = -pedantic-errors -std=c++11
LDLIBS = -lncurses
#//////////////////////////////
$(src)menu.o: $(lib)menu.cpp $(inc)menu.h
	g++ $(FLAG) -c $< $(LDLIBS) -o $@
$(src)main_game.o: $(lib)main_game.cpp $(inc)main_game.h $(inc)menu.h
	g++ $(FLAG) -c $< $(LDLIBS) -o $@
$(src)main.o: $(lib)main.cpp $(inc)menu.h
	g++ $(FLAG) -c $< $(LDLIBS) -o $@


#//////////////////////////////

main: $(src)main.o $(src)menu.o $(src)main_game.o
	g++ $(FLAG) $^ $(LDLIBS) -o $@


#//////////////////////////////

run:
	./main

.PHONY: run

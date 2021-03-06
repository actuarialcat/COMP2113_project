lib = lib/
src = src/
inc = include/
FLAG = -pedantic-errors -std=c++11

#//////////////////////////////
$(src)game_object.o: $(lib)game_object.cpp $(inc)game_object.h $(inc)Character.h
	g++ $(FLAG) -c $< -o $@

$(src)game_display.o: $(lib)game_display.cpp $(inc)game_display.h $(inc)Character.h $(inc)Map.h
	g++ $(FLAG) -c $< -o $@

$(src)menu.o: $(lib)menu.cpp $(inc)menu.h $(inc)main_game.h
	g++ $(FLAG) -c $< -o $@

$(src)main_game.o: $(lib)main_game.cpp $(inc)main_game.h $(inc)menu.h $(inc)Character.h $(inc)Map.h $(inc)game_display.h
	g++ $(FLAG) -c $< -o $@

$(src)Character.o: $(lib)Character.cpp $(inc)Character.h
	g++ $(FLAG) -c $< -o $@

$(src)Map.o: $(lib)Map.cpp $(inc)Map.h
	g++ $(FLAG) -c $< -o $@

$(src)main.o: $(lib)main.cpp $(inc)menu.h
	g++ $(FLAG) -c $< -o $@


#//////////////////////////////

main: $(src)main.o $(src)menu.o $(src)main_game.o $(src)Character.o $(src)Map.o $(src)game_display.o $(src)game_object.o
	g++ $(FLAG) $^ -o $@


#//////////////////////////////

run:
	./main

.PHONY: run

#//////////////////////////////
#adhoc testing, please ignore

test_file/test.o: test_file/test.cpp $(inc)game_object.h $(inc)Character.h
	g++ $(FLAG) -c $< -o $@

test: test_file/test.o $(src)game_object.o $(src)Character.o
	g++ $(FLAG) $^ -o $@

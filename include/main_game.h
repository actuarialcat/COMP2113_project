#ifndef MAIN_GAME_H_
#define MAIN_GAME_H_
/*
I don't know why it said "Character not declared in this scope"
if I don't include Character.h here
*/
#include "../include/Character.h"
void MainGameInit();
void NextFloor(Character &p);
#endif

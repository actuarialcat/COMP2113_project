#include <ctime>
#include <cstdlib>

#include "../include/Character.h"

Character::Character(char sym){
  symbol = sym;
  max_hp = 30;
  hp = 30;
  doom_mode = false;
  //randomize starting location
  srand(time(NULL));
  //need to modify mannually if we change the map size
  y = rand() % 10;
  x = rand() % 20;
  flr = 1;
  score = 0;
  num_of_enemy = 0;
}

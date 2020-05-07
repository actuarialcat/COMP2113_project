#include <ctime>
#include <cstdlib>

#include "../include/Character.h"

Character::Character(char sym){
  symbol = sym;
  lv = 1;
  expr = 100;
  max_hp = 30;
  hp = 30;
  //randomize starting location
  srand(time(NULL));
  y = rand() % 10; //need to modify mannually if we change the map size
  x = rand() % 20;
  flr = 1;
  score = 0;
  num_of_enemy = 0;
}

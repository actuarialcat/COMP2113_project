#include "../include/Character.h"

Character::Character(char sym){
  symbol = sym;
  lv = 1;
  expr = 100;
  max_hp = 100;
  hp = 100;
  y = 0;
  x = 0;
  flr = 1;
  score = 0;
  num_of_enemy = 0;
}

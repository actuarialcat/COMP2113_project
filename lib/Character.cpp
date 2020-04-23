#include "../include/Character.h"

Character::Character(char sym){
  symbol = sym;
  lv = 1;
  expr = 100;
  max_hp = 30;
  hp = 30;
  y = 1;
  x = 1;
  flr = 1;
  score = 0;
}

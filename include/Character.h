#ifndef CHARACTER_H
#define CHARACTER_H

class Character {
public:
  //variable
  char symbol;
  int flr;
  int lv;
  int expr; //expereince needed to level up
  int max_hp, hp;
  int y, x;
  int score;

  //Constructer
  Character(char sym);

  //void level_up();


};

#endif

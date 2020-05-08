#ifndef CHARACTER_H
#define CHARACTER_H



class Character {
public:
  //the character image
  char symbol;

  //floor the player at
  int flr;

  //current hp and maximum hp of the character
  int max_hp, hp;

  //coordinate of the character
  int y, x;

  //current score of the character
  int score;

  //number of hidden enemies left in the current floor
  int num_of_enemy;


  //for mode inherit
  bool doom_mode;


  //Constructer
  Character(char sym);

  //void level_up();


};



#endif

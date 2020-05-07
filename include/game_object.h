#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <string>
#include "../include/Character.h"

/////////////////////////////////////////////
//Base Class

class GameObjectBase
{
public:
  //fuctions
  char getDisplayChar();

  virtual bool collisionCheck(Character &player, std::string message[]);   //True for movable, False for collision
  virtual bool postMoveAction(Character &player, std::string message[]);   //True for suicide after pass on.

protected:
  //Constructer
  GameObjectBase(char display_symbol);

  //variables
  char display_char;

};


/////////////////////////////////////////////
//Game Objects

class ObjectWall : public GameObjectBase
{
public:
  //Constructer
  ObjectWall(char display_symbol);

  //fuctions
  bool collisionCheck(Character &player, std::string message[]);
  bool postMoveAction(Character &player, std::string message[]);

};


//---------------------------------------------

class ObjectFloor : public GameObjectBase
{
public:
  //Constructer
  ObjectFloor(char display_symbol);

  //fuctions
  bool collisionCheck(Character &player, std::string message[]);
  bool postMoveAction(Character &player, std::string message[]);

};


//---------------------------------------------

class ObjectEnemy : public GameObjectBase
{
public:
  //Constructer
  ObjectEnemy(char display_symbol, int init_lvl);

  //fuctions
  bool collisionCheck(Character &player, std::string message[]);
  bool postMoveAction(Character &player, std::string message[]);

private:
  //variables
  int hp;
  int lvl;
  bool ambush;

  //fuctions
  int Dice(int lvl);
  void ambush_combat(Character &p, int lvl, std::string message[]);
  void direct_combat(Character &p, int &hp, int lvl, std::string message[]);
};

//---------------------------------------------

class ObjectPotion : public GameObjectBase
{
public:
  //Constructer
  ObjectPotion(char display_symbol, int init_size);

  //fuctions
  bool collisionCheck(Character &p, std::string message[]);
  bool postMoveAction(Character &p, std::string message[]);

private:
  //variables
  int size;
  double perc_heal;
  bool hidden;

  //fuctions
  void reveal(std::string message[]);
  void replanish_hp(Character &p, std::string message[]);
};

//---------------------------------------------

class ObjectHealthGem : public GameObjectBase
{
public:
  //Constructer
  ObjectHealthGem(char display_symbol, int init_size);

  //fuctions
  bool collisionCheck(Character &p, std::string message[]);
  bool postMoveAction(Character &p, std::string message[]);

private:
  //variables
  int size;
  int hp_increase;
  bool hidden;

  //fuctions
  void reveal(std::string message[]);
  void addMaxHP(Character &p, std::string message[]);
};

//---------------------------------------------

class ObjectTreasure : public GameObjectBase
{
public:
  //Constructer
  ObjectTreasure(char display_symbol, int init_size);

  //fuctions
  bool collisionCheck(Character &p, std::string message[]);
  bool postMoveAction(Character &p, std::string message[]);

private:
  //variables
  int size;
  int score_increase;
  bool hidden;

  //fuctions
  void reveal(std::string message[]);
  void addscore(Character &p, std::string message[]);
};
//-------------------------------------------------

class ObjectStair : public GameObjectBase
{
public:
  //Constructer
  ObjectStair(char display_symbol, int floor);

  //functions
  bool collisionCheck(Character &p, std::string message[]);
  bool postMoveAction(Character &p, std::string message[]);
private:
  int floor;
  int score_increase; //increase score if pass a floor
  bool hidden;

  //functions
  void reveal(std::string message[]);
  void addscore(Character &p, std::string message[]);
};



#endif

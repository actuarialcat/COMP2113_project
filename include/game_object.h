#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "../include/Character.h"

/////////////////////////////////////////////
//Base Class

class GameObjectBase
{
public:
  //fuctions
  char getDisplayChar();

  virtual int collisionCheck(Character &player);   //0 for pass, 1 for collision
  virtual void postMoveAction(Character &player);

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
  int collisionCheck(Character &player);
  void postMoveAction(Character &player);

};


//---------------------------------------------

class ObjectFloor : public GameObjectBase
{
public:
  //Constructer
  ObjectFloor(char display_symbol);

  //fuctions
  int collisionCheck(Character &player);
  void postMoveAction(Character &player);

};


//---------------------------------------------

class ObjectEnemy : public GameObjectBase
{
public:
  //Constructer
  ObjectEnemy(char display_symbol, int init_hp);

  //fuctions
  int collisionCheck(Character &player);
  void postMoveAction(Character &player);

private:
  //variables
  int hp;


};






#endif

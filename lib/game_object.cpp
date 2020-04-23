#include "../include/Character.h"
#include "../include/game_object.h"

#include <iostream>

/////////////////////////////////////////////
//GameObjectBase

GameObjectBase::GameObjectBase(char display_symbol) {
  display_char = display_symbol;
}

char GameObjectBase::getDisplayChar() {
  return display_char;
}

int GameObjectBase::collisionCheck(Character &player){
  return 1;
}

void GameObjectBase::postMoveAction(Character &player){
  //do nothing
}


/////////////////////////////////////////////
//ObjectWall

ObjectWall::ObjectWall(char display_symbol) : GameObjectBase(display_symbol) {
  //do nothing
}

int ObjectWall::collisionCheck(Character &player){
  return 1;
}

void ObjectWall::postMoveAction(Character &player){
  //do nothing
}


/////////////////////////////////////////////
//ObjectFloor

ObjectFloor::ObjectWall(char display_symbol) : GameObjectBase(display_symbol) {
  //do nothing
}

int ObjectFloor::collisionCheck(Character &player){
  return 0;
}

void ObjectFloor::postMoveAction(Character &player){
  //do nothing
}


/////////////////////////////////////////////
//ObjectEnemy

ObjectEnemy::ObjectEnemy(char display_symbol, int init_hp)
: GameObjectBase(display_symbol)
{
  hp = init_hp;
}

int ObjectEnemy::collisionCheck(Character &player){
  //TODO:
  return 1;
}

void ObjectEnemy::postMoveAction(Character &player){
  //TODO:
}


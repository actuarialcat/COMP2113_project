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

bool GameObjectBase::collisionCheck(Character &player){
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

bool ObjectWall::collisionCheck(Character &player){
  return false;
}

void ObjectWall::postMoveAction(Character &player){
  //do nothing
}


/////////////////////////////////////////////
//ObjectFloor

ObjectFloor::ObjectFloor(char display_symbol) : GameObjectBase(display_symbol) {
  //do nothing
}

bool ObjectFloor::collisionCheck(Character &player){
  return true;
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

bool ObjectEnemy::collisionCheck(Character &player){
  //TODO:
  return true;
}

void ObjectEnemy::postMoveAction(Character &player){
  //TODO:
}


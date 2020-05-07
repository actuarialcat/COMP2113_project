#include "../include/Character.h"
#include "../include/game_object.h"

#include <string>
#include <iostream>

using namespace std;

/////////////////////////////////////////////
//GameObjectBase

GameObjectBase::GameObjectBase(char display_symbol) {
  display_char = display_symbol;
}

char GameObjectBase::getDisplayChar() {
  return display_char;
}

bool GameObjectBase::collisionCheck(Character &player, std::string message[]){
  return 1;
}

void GameObjectBase::postMoveAction(Character &player, std::string message[]){
  //do nothing
}


/////////////////////////////////////////////
//ObjectWall

ObjectWall::ObjectWall(char display_symbol) : GameObjectBase(display_symbol) {
  //do nothing
}

bool ObjectWall::collisionCheck(Character &player, std::string message[]){
  return false;
}

void ObjectWall::postMoveAction(Character &player, std::string message[]){
  //do nothing
}


/////////////////////////////////////////////
//ObjectFloor

ObjectFloor::ObjectFloor(char display_symbol) : GameObjectBase(display_symbol) {
  //do nothing
}

bool ObjectFloor::collisionCheck(Character &player, std::string message[]){
  return true;
}

void ObjectFloor::postMoveAction(Character &player, std::string message[]){
  //do nothing
}


/////////////////////////////////////////////
//ObjectEnemy

int Dice(int lvl);
void enemy_ambush_combat(Character &player, int lvl, string message[]);
void enemy_direct_combat(Character &player, int &hp, int lvl, string message[]);


ObjectEnemy::ObjectEnemy(char display_symbol, int init_lvl)
: GameObjectBase(display_symbol)
{
  lvl = init_lvl;

  hp = 10 * lvl;
  ambush = true;
}

bool ObjectEnemy::collisionCheck(Character &player, std::string message[]){
  if (ambush){
    enemy_ambush_combat(player, lvl, message);
    ambush = false;
    return false;
  }
  else {
    return true;
  }
}

void ObjectEnemy::postMoveAction(Character &player, std::string message[]){
  if (hp > 0){
    enemy_direct_combat(player, hp, lvl, message);
    display_char = 'x';
  }
}


void enemy_ambush_combat(Character &p, int lvl, string message[]){
  int damage = Dice(lvl);

  message[0] = "Ambushed by monster.";
  string message_1 = "You lost ";
  message_1.append(to_string(damage));
  message_1.append(" hp.");
  message[1] = message_1;

  p.hp -= damage;
}

void enemy_direct_combat(Character &p, int &hp, int lvl, string message[]){
  int damage = hp;

  string message_0 = "You attacked monster with ";
  message_0.append(to_string(hp));
  message_0.append(" hp.");
  message[0] = message_0;

  if(p.hp > 0){
    string message_1 = "You lost ";
    message_1.append(to_string(damage));
    message_1.append(" hp.");
    message[1] = message_1;
  }
  else {
    message[1] = "You died";
  }

  hp = 0;
  p.hp -= damage;
}

int Dice(int lvl) {
  srand(time(NULL));
  int damage = 3; //base damage

  for (int i=0; i<2; i++) { 
    damage += rand() % lvl + 1;
  }

  return damage;
}


/////////////////////////////////////////////
//ObjectEnemy


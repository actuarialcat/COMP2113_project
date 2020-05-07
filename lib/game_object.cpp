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

ObjectEnemy::ObjectEnemy(char display_symbol, int init_lvl)
: GameObjectBase(display_symbol)
{
  lvl = init_lvl;

  hp = 10 * lvl;
  ambush = true;
}

bool ObjectEnemy::collisionCheck(Character &player, std::string message[]){
  if (ambush){
    ambush_combat(player, lvl, message);
    ambush = false;
    return false;
  }
  else {
    return true;
  }
}

void ObjectEnemy::postMoveAction(Character &player, std::string message[]){
  if (hp > 0){
    direct_combat(player, hp, lvl, message);
    display_char = 'x';
  }
}

//---------------------------------------------

void ObjectEnemy::ambush_combat(Character &p, int lvl, std::string message[]){
  int damage = Dice(lvl);

  message[0] = "Ambushed by monster.";
  string message_1 = "You lost ";
  message_1.append(to_string(damage));
  message_1.append(" hp.");
  message[1] = message_1;

  p.hp -= damage;
}

void ObjectEnemy::direct_combat(Character &p, int &hp, int lvl, std::string message[]){
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

int ObjectEnemy::Dice(int lvl) {
  srand(time(NULL));
  int damage = 3; //base damage

  for (int i=0; i<2; i++) { 
    damage += rand() % lvl + 1;
  }

  return damage;
}

/////////////////////////////////////////////
//ObjectPotion

ObjectPotion::ObjectPotion(char display_symbol, int init_size) 
: GameObjectBase(display_symbol)
{  
  size = init_size;
  
  perc_heal = (size == 1) ? 0.5 : 1;    //size 1=small, 2=large
  hidden = false;
}

bool ObjectPotion::collisionCheck(Character &player, std::string message[]){
  if (hidden){
    reveal(message);
    hidden = false;
    return false;
  }
  else {
    return true;
  }
}

void ObjectPotion::postMoveAction(Character &player, std::string message[]){
  replanish_hp(player, perc_heal, message);
}

//---------------------------------------------

void ObjectPotion::reveal(std::string message[]) {

  string message_0 = "You found a ";
  message_0.append((size == 1) ? "small" : "large");
  message_0.append(" health potion.");
  message[0] = message_0;

  message[1] = "";
}

void ObjectPotion::replanish_hp(Character &p, int perc_heal, std::string message[]) {
  int hp_healed;
  int potent = (int)(p.max_hp * perc_heal);

  if (p.hp + potent > p.max_hp) {
    hp_healed = p.max_hp - p.hp;
    p.hp = p.max_hp;
  }
  else {
    hp_healed = potent;
    p.hp = p.hp + potent;
  }
  
  message[0] = "You used a health potion.";
  string message_1 = "You healed ";
  message_1.append(to_string(hp_healed));
  message_1.append(" hp.");
  message[1] = message_1;
}

/////////////////////////////////////////////
//ObjectPotion









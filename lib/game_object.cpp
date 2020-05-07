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
  return false;
}

bool GameObjectBase::postMoveAction(Character &player, std::string message[]){
  return false;
}


/////////////////////////////////////////////
//ObjectWall

ObjectWall::ObjectWall(char display_symbol) : GameObjectBase(display_symbol) {
  //do nothing
}

bool ObjectWall::collisionCheck(Character &player, std::string message[]){
  return false;
}

bool ObjectWall::postMoveAction(Character &player, std::string message[]){
  return false;
}


/////////////////////////////////////////////
//ObjectFloor

ObjectFloor::ObjectFloor(char display_symbol) : GameObjectBase(display_symbol) {
  //do nothing
}

bool ObjectFloor::collisionCheck(Character &player, std::string message[]){
  return true;
}

bool ObjectFloor::postMoveAction(Character &player, std::string message[]){
  return false;
}


/////////////////////////////////////////////
//ObjectEnemy

ObjectEnemy::ObjectEnemy(char display_symbol, int init_lvl)
: GameObjectBase(display_symbol)
{
  lvl = init_lvl;

  hp = Dice(lvl) / 2; //lose half the ambush damage
  ambush = true;
}

bool ObjectEnemy::collisionCheck(Character &player, std::string message[]){
  if (ambush){
    //counting the hidden enemies left
    player.num_of_enemy--;
    ambush_combat(player, lvl, message);
    ambush = false;
    return false;
  }
  else {
    return true;
  }
}

bool ObjectEnemy::postMoveAction(Character &player, std::string message[]){
  direct_combat(player, hp, lvl, message);

  player.num_of_enemy--;
  return true;
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
    message[1] = "You run out of hp and have to leave the dungeon.";
  }

  hp = 0;
  p.hp -= damage;
}

int ObjectEnemy::Dice(int lvl) {
  srand(time(NULL));
  int damage = 0; //base damage

  for (int i=0; i<2; i++) {
    damage += rand() % (lvl*2) + 3;
  }

  return damage;
}

/////////////////////////////////////////////
//ObjectPotion

ObjectPotion::ObjectPotion(char display_symbol, int init_size)
: GameObjectBase(display_symbol)
{
  size = init_size;

  //where we change the heal percentage
  perc_heal = (size == 1) ? 0.1 : 0.25;    //size 1=small, 2=large
  hidden = true;
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

bool ObjectPotion::postMoveAction(Character &player, std::string message[]){
  replanish_hp(player, message);
  return true;
}

//---------------------------------------------

void ObjectPotion::reveal(std::string message[]) {

  string message_0 = "You found a ";
  message_0.append((size == 1) ? "small" : "large");
  message_0.append(" health potion.");
  message[0] = message_0;

  message[1] = "";
}

void ObjectPotion::replanish_hp(Character &p, std::string message[]) {
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

  string message_0 = "You used a ";
  message_0.append((size == 1) ? "small" : "large");
  message_0.append(" health potion.");
  message[0] = message_0;

  string message_1 = "You healed ";
  message_1.append(to_string(hp_healed));
  message_1.append(" hp.");
  message[1] = message_1;
}

/////////////////////////////////////////////
//ObjectHealthGem

ObjectHealthGem::ObjectHealthGem(char display_symbol, int init_size)
: GameObjectBase(display_symbol)
{
  size = init_size;

  hp_increase = (size == 1) ? 3 : 6;    //size 1=small, 2=large
  hidden = true;
}

bool ObjectHealthGem::collisionCheck(Character &player, std::string message[]){
  if (hidden){
    reveal(message);
    hidden = false;
    return false;
  }
  else {
    return true;
  }
}

bool ObjectHealthGem::postMoveAction(Character &player, std::string message[]){
  addMaxHP(player, message);
  return true;
}

//---------------------------------------------

void ObjectHealthGem::reveal(std::string message[]) {

  string message_0 = "You found a ";
  message_0.append((size == 1) ? "small" : "large");
  message_0.append(" health gem.");
  message[0] = message_0;

  message[1] = "";
}

void ObjectHealthGem::addMaxHP(Character &p, std::string message[]) {

  p.max_hp = p.max_hp + hp_increase;
  p.hp = p.hp + hp_increase;

  string message_0 = "You used a ";
  message_0.append((size == 1) ? "small" : "large");
  message_0.append(" health gem.");
  message[0] = message_0;

  string message_1 = "Your max HP is increased by ";
  message_1.append(to_string(hp_increase));
  message_1.append(" hp.");
  message[1] = message_1;
}

/////////////////////////////////////////////
//ObjectTreasure

ObjectTreasure::ObjectTreasure(char display_symbol, int init_size)
: GameObjectBase(display_symbol)
{
  size = init_size;

  score_increase = (size == 1) ? 20 : 50;    //size 1=small, 2=large
  hidden = true;
}

bool ObjectTreasure::collisionCheck(Character &player, std::string message[]){
  if (hidden){
    reveal(message);
    hidden = false;
    return false;
  }
  else {
    return true;
  }
}

bool ObjectTreasure::postMoveAction(Character &player, std::string message[]){
  addscore(player, message);
  return true;
}

//---------------------------------------------

void ObjectTreasure::reveal(std::string message[]) {

  string message_0 = "You found a ";
  message_0.append((size == 1) ? "small" : "large");
  message_0.append(" treasure.");
  message[0] = message_0;

  message[1] = "";
}

void ObjectTreasure::addscore(Character &p, std::string message[]) {

  p.score = p.score + score_increase;

  string message_0 = "You open a ";
  message_0.append((size == 1) ? "small" : "large");
  message_0.append(" treasure.");
  message[0] = message_0;

  string message_1 = "Your gain ";
  message_1.append(to_string(score_increase));
  message_1.append(" score.");
  message[1] = message_1;
}
//////////////////////////////////////////////////////////
//Object Stair
ObjectStair::ObjectStair(char display_symbol, int floor)
: GameObjectBase(display_symbol)
{
  floor = floor;
  score_increase = 100;
  hidden = true;
}

bool ObjectStair::collisionCheck(Character &player, std::string message[]){
  if (hidden){
    reveal(message);
    hidden = false;
    return false;
  }
  else {
    return true;
  }
}

bool ObjectStair::postMoveAction(Character &player, std::string message[]){
  addscore(player, message);
  return true;
}
//-------------------------------------------------
void ObjectStair::reveal(std::string message[]) {

  string message_0 = "You found the staircase.";
  message[0] = message_0;

  message[1] = "";
}

void ObjectStair::addscore(Character &p, std::string message[]) {

  p.score = p.score + score_increase;

  string message_0 = "You gain 100 score for passing this floor.";
  message[0] = message_0;

  string message_1 = "Press any key to climb to the next floor.";
  message[1] = message_1;

}

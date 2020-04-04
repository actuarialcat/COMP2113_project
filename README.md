# COMP2113_project
COMP 2113 Project for Group 225
--------------------------------------------------------------
Brief identification of the team members
----------------------------------------
Fong Cheuk Ting, u3035688784
[Your name], [Your UID]
--------------------------------------------------------------
Game description with basic game rules
-----------------------------------------
The game we decided to develop is "魔塔". It is fixed-values RPG with fixed battle result, fixed enemy and fixed rescources such that every same decision will always results in same outcome. However, An extra new gamemode willbe develped with random elements to make the gamemode more "roguelike".

In the game, you will control the champion who attempts to challenge a magical tower. Your goal is to climb to the top to defeat the final boss in order to save the world. The tower is full of dangerous monsters that block your way to the top. You have to battle against them and they will deal damage to you. If your health drop to zero, you will die. Luckily, the tower is also full of strategic resources to help you getting stronger and win the game.
--------------------------------------------------------------
Features and functions
-----------------------
Features of the champion:
struct Champion{
  int level; //level
  int hp; //health
  int atk; //attack
  int def; //defence
  int msd; //magical shield
  int pos_floor, pos_x, pos_y; //position in the tower
  int exp; //experience need to level up
  int gold; //
  int yellow_key, blue_key, red_key //number of keys
  int face //the direction you are facing
}
Features of monsters
struct Monster{
  string name; //name of monsters
  int level; //level of monster
  int hp; //health
  int atk; //attack
  int def; //defence
  int atrrib; //special ability, such as "first strike"
  int exp; //experience gained from killing it
  int gold; //gold gained from killing it
}
Battle damage formula:
int battle(Champion c, Monster e){
  //basic damage part
  if (c.atk <= e.def){
    return -1; //can't penetrate enemy's armer, undefeatable
  }
  double avg_turn = e.hp / (c.atk-e.def);
  int turn_taken = ceil(avg_turn);
  int dpt = e.atk - c.def; //damage deal to the champion per turn
  if (dpt < 0){
    dpt = 0;
  }
  //special damage part
  if (e.attrib == "first stirke"){
    turn_taken++;
  }
  if .....
  return dpt * turn_taken - c.msd
}

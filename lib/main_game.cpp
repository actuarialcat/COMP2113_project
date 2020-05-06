#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

#include "../include/menu.h"
#include "../include/Character.h"
#include "../include/Map.h"
#include "../include/game_display.h"

/////////////////////////////////////////////
//private functions declaration

void GameLoop(Character p, Map m, string message[]);
bool check_not_end_game();
char InputStage();
void LogicStage(Character &p, Map &m, string message[], char move);
int Dice(int floor);


//Manu Logic
void Gameover();


/////////////////////////////////////////////


/////////////////////////////////////////////

//Game Initialization
void MainGameInit(){
  int height, width;
  height = 10;
  width = 20;
  //Init character
  Character p('@');

  //Init Map
  Map m(height, width, p.flr);

  //Init message
  /*
  first line of message: tell player what happen
  e.g. You encountered an enemy!
  seocnd line of message: display data change
  e.g. You lost 9 hp
  */
  string message[2] = {"You entered the 1st floor of the dungeon.",
   "Press w/a/s/d to move"};
   //reveal map under 3x3 areas of the starting point
   for (int i=-1;i<=1;i++){
     for (int j=-1;j<=1;j++){
       //check boundary condition
       if (p.y+i >= 0 && p.y+i < m.height &&
       p.x+j >= 0 && p.x+j < m.width){
         m.discovery_layer[p.y+i][p.x+j] = ' ';
       }
     }
   }
  //start game
  GameLoop(p, m, message);
}

/////////////////////////////////////////////
//Game Logic
void GameLoop(Character p, Map m, string message[]){
  //reasons for ending the current game loop
  bool died = false;
  bool upstair = false;
  bool save_game = false;
  //display everything
  GameDisplay(p, m, message);

  //start the actual loop
  while (true){
    //Input stage
    char move = InputStage();

    //Logic stage
    LogicStage(p, m, message, move);

    //Gameover determination
    if (p.hp <= 0){
      died = true;
      break;
    }

    //Display stage
    GameDisplay(p, m, message);

  }
  Gameover();
}
//--------------------------------------------
char InputStage(){
  bool valid = false;
  char input;
  while (!valid){
    cin >> input;
    if (input == 'w' || input == 'a' || input == 's' || input == 'd'){
      valid = true;
    }
  }
  return input;
}
//--------------------------------------------
void LogicStage(Character &p, Map &m, string message[], char move){
  //the supposed destination after moving
  int dst_y = p.y;
  int dst_x = p.x;
  if (move == 'w'){dst_y--;}
  if (move == 's'){dst_y++;}
  if (move == 'a'){dst_x--;}
  if (move == 'd'){dst_x++;}
  //check boundary condition
  if (dst_y < 0 || dst_y >= m.height ||
  dst_x < 0 || dst_x >= m.width){
    message[0] = "This is the edge of the dungeon.";
    message[1] = "";
  } else {
    //if ?, then reveal tile
    if (m.discovery_layer[dst_y][dst_x] == '?'){
      m.discovery_layer[dst_y][dst_x] = ' ';
      p.score++;
      if (m.object_layer[dst_y][dst_x]->getDisplayChar() == 'E'){
        //roll dice to randomize damage
        int damage = Dice(m.floor);
        //change message
        message[0] = "Ambushed by monster.";
        string message_1 = "You lost ";
        message_1.append(to_string(damage));
        message_1.append(" hp.");
        message[1] = message_1;
        p.hp -= damage;
      }
    } else {
      //if nothing there, move
      if (m.object_layer[dst_y][dst_x]->getDisplayChar() == ' '){
        p.y = dst_y;
        p.x = dst_x;
      } else {
        //react with game objects
      }
    }
  }
}
//--------------------------------------------
int Dice(int floor){
  srand(time(NULL));
  int damage = 3; //base damage
  for (int i=0;i<2;i++){
    damage += rand() % floor + 1;
  }
  return damage;

}
/////////////////////////////////////////////
//Manu Logic

void Gameover()
{
  cout << "Gameover" << endl;
  cout << "Press any key to go back to menu" << endl;
  char input;
  cin >> input;
  MainMenuInit();
}

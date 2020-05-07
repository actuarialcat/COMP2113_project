#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

#include "../include/menu.h"
#include "../include/Character.h"
#include "../include/Map.h"
#include "../include/game_display.h"

using namespace std;

/////////////////////////////////////////////
//private functions declaration

void reveal_starting_map(Character &p, Map &m);
bool check_boundary_condition(int x, int y, Map m);

void GameLoop(Character &p, Map &m, string message[]);
bool check_not_end_game(Character p);
void reveal_map(Character &p, Map &m, int move_target_x, int move_target_y);

int MoveInput(int &move_target_x, int &move_target_y);

//void LogicStage(Character &p, Map &m, string message[], char move);
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
  reveal_starting_map(p, m);

  //Init message
  /*
  first line of message: tell player what happen
  e.g. You encountered an enemy!
  seocnd line of message: display data change
  e.g. You lost 9 hp
  */
  string message[2] = {"You entered the 1st floor of the dungeon.",
   "Press w/a/s/d to move"};

  //start game
  GameLoop(p, m, message);
}

//--------------------------------------------

void reveal_starting_map(Character &p, Map &m) {
  for (int i=-1;i<=1;i++){
    for (int j=-1;j<=1;j++){
      //check boundary condition
      if (check_boundary_condition(p.x+j, p.y+i, m)){
        m.discovery_layer[p.y+i][p.x+j] = ' ';
      }
    }
  }
}

bool check_boundary_condition(int x, int y, Map m) {
  if (y >= 0 && y < m.height && x >= 0 && x < m.width){
    return true;
  }
  else {
    return false;
  }
}

/////////////////////////////////////////////
//Game Logic

void GameLoop(Character &p, Map &m, string message[]){
  int move_target_x, move_target_y;

  while(check_not_end_game(p)){
    move_target_x = p.x;
    move_target_y = p.y;

    //display everything
    GameDisplay(p, m, message);

    //control input
    int x = MoveInput(move_target_x, move_target_y);

    if (check_boundary_condition(move_target_x, move_target_y, m)) {
      reveal_map(p, m, move_target_x, move_target_y);

      //collision check and pre-move interaction
      if( m.object_layer[move_target_y][move_target_x]->collisionCheck(p, message) ){
        p.y = move_target_y;    //moving
        p.x = move_target_x;

        m.object_layer[p.y][p.x]->postMoveAction(p, message);   //post move interaction
      }
    }
    else {
      message[0] = "This is the edge of the dungeon.";
      message[1] = "";
    }



  }
  Gameover();
}

//---------------------------------------------

bool check_not_end_game(Character p){
  if (p.hp > 0) {return true; }

  return false;
}

void reveal_map(Character &p, Map &m, int dst_x, int dst_y){
  if (m.discovery_layer[dst_y][dst_x] == '?'){
      m.discovery_layer[dst_y][dst_x] = ' ';
      p.score++;
  }
}


//Get user GUI input
int MoveInput(int &move_target_x, int &move_target_y) {
  bool valid;
  char input;

  while(!valid){
    std::cin >> input;

    valid = true;
    switch(input) {
      case 'w':
        move_target_y--;
        break;

      case 's':
        move_target_y++;
        break;

      case 'a':
        move_target_x--;
        break;

      case 'd':
        move_target_x++;
        break;

      /*call game pause manu;
      case :
        break;
      */
      default:
        valid = false;
        break;
    }
  }

  return input;
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


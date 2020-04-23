#include <ncurses.h>
#include <string>

#include "../include/menu.h"
#include "../include/Character.h"
#include "../include/Map.h"
#include "../include/game_display.h"

/////////////////////////////////////////////
//private functions declaration

void GameLoop(Character, Map, WINDOW * &, WINDOW * &, WINDOW * &);
bool check_not_end_game();
int MoveInput(WINDOW *dungeon, int &move_target_x, int &move_target_y);


//Manu Logic
void Gameover();


/////////////////////////////////////////////


/////////////////////////////////////////////

//Game Initialization
void MainGameInit(){
  WINDOW *stats, *dungeon, *datalog;

  int height, width;
  height = 10;
  width = 20;

  //Init Display
  InitGameDisplay(stats, dungeon, datalog, height, width);  //game_display.h

  //Init character
  Character player('@');

  //Init Map
  Map game_map(height, width, player.flr);

  //generate map objects

  //start game
  GameLoop(player, game_map, stats, dungeon, datalog);
}

/////////////////////////////////////////////
//Game Logic

void GameLoop(Character player, Map game_map,
    WINDOW *&stats, WINDOW *&dungeon, WINDOW *&datalog){

  bool end_game = false;
  string test_str = "Test";

  //reveal map under starting point
  game_map.discovery_layer[player.y][player.x] = ' ';
  
  while(check_not_end_game()){
    int input, move_dir_x = 0, move_dir_y = 0;
    int move_target_x, move_target_y;

    //testing
    test_str = to_string(player.y) + " " + to_string(player.x);

    //display everything
    update_all_display(player, game_map, test_str, stats, dungeon, datalog);    //game_display.h

    //control input
    int x = MoveInput(datalog, move_dir_x, move_dir_y);
    move_target_y = player.y + move_dir_y;
    move_target_x = player.x + move_dir_x;

    //collision check and pre-move interaction
    if( game_map.object_layer[move_target_y][move_target_x]->collisionCheck(player) ){
      //moving
      player.y = move_target_y;
      player.x = move_target_x;

      //reveal map
      game_map.discovery_layer[player.y][player.x] = ' ';

      //post move interaction
      game_map.object_layer[player.y][player.x]->postMoveAction(player);
    }

  }
  Gameover();
}

//---------------------------------------------

bool check_not_end_game(){
  return true;
}


//Get user GUI input
int MoveInput(WINDOW *dungeon, int &move_target_x, int &move_target_y) {
  bool valid = false;
  int input;

  wrefresh(dungeon);
  keypad(dungeon, true);

  while(!valid){
    input = wgetch(dungeon);

    switch(input) {
      case KEY_UP:
        move_target_x = 0;
        move_target_y = -1;
        valid = true;
        break;

      case KEY_DOWN:
        move_target_x = 0;
        move_target_y = 1;
        valid = true;
        break;

      case KEY_LEFT:
        move_target_x = -1;
        move_target_y = 0;
        valid = true;
        break;

      case KEY_RIGHT:
        move_target_x = 1;
        move_target_y = 0;
        valid = true;
        break;

      /*call game pause manu;
      case :
        
        valid = true;
        break;
      */

      default:
        valid = true;
        break;
    }
  }

  return input;
}


/////////////////////////////////////////////
//Manu Logic

void Gameover()
{
  clear();
  MainMenuInit();
}


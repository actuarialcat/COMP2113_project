#include <ncurses.h>
#include <string>

#include "../include/menu.h"
#include "../include/Character.h"
#include "../include/Map.h"
#include "../include/game_display.h"

/////////////////////////////////////////////
//private functions declaration

void GameLoop(Character, Map, WINDOW * &, WINDOW * &, WINDOW * &);


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
  Character p('@');

  //Init Map
  Map m(height, width, p.flr);

  //generate map objects

  //start game
  GameLoop(p, m, stats, dungeon, datalog);
}

/////////////////////////////////////////////
//Game Logic

void GameLoop(Character p,Map m, WINDOW * & stats, WINDOW * & dungeon, 
    WINDOW * & datalog)
{
  //display everything
  update_all_display(p, m, "", stats, dungeon, datalog);    //game_display.h

  while(true)
  {
    int input = wgetch(dungeon);

  }
  Gameover();
}



/////////////////////////////////////////////
//Manu Logic

void Gameover()
{
  clear();
  MainMenuInit();
}

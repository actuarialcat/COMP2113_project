#include <ncurses.h>
#include <string>

#include "../include/Character.h"
#include "../include/Map.h"

/////////////////////////////////////////////
//Private functions declaration

void update_stats(Character, WINDOW *);
void update_dungeon(Map, WINDOW *);
void update_datalog(string, WINDOW * datalog);


/////////////////////////////////////////////
//Display Functions

//Initilize
void InitGameDisplay(WINDOW *&stats, WINDOW *&dungeon, WINDOW *&datalog, 
    int height, int width){

  //clear the menu
  clear();

  //Init three panel
  stats = newwin(height+2,10,0,0);
  box(stats, 0, 0);

  dungeon = newwin(height+2,width+2,0,10);
  box(dungeon, 0, 0);

    //used to display game event message e.g. level up, ambushed by monster
  datalog = newwin(4, 10+width+2, height+2, 0); 
  box(datalog, 0, 0);

}


//Update display
void update_all_display(Character p, Map m, string message, WINDOW *stats, WINDOW *dungeon, 
    WINDOW *datalog) {
  refresh();
  update_stats(p, stats);
  update_dungeon(m, dungeon);
  update_datalog(message, datalog);

}


/////////////////////////////////////////////
//Private functions

void update_stats(Character p, WINDOW *stats)
{
  wclear(stats);
  box(stats, 0, 0);
  mvwprintw(stats, 1, 1, "Floor %d", p.flr);
  mvwprintw(stats, 3, 1, "Level %d", p.lv);
  mvwprintw(stats, 5, 1, "Exp %d", p.expr);
  mvwprintw(stats, 7, 1, "Hp %d/%d", p.hp, p.max_hp);
  mvwprintw(stats, 9, 1, "Score:");
  mvwprintw(stats, 10, 1, "%d", p.score);
  wrefresh(stats);
}

void update_dungeon(Map m, WINDOW *dungeon)
{
  wclear(dungeon);
  box(dungeon, 0, 0);
  mvwprintw(dungeon, 1, 1, "%c", m.map[0][1][1]);

  for (int i=0;i<m.height;i++) //I don't know why m.height and m.width don't work
  {
    for (int j=0;j<m.width;j++)
    {
      if (m.map[0][i][j] != ' ')
        mvwprintw(dungeon, i+1, j+1, "%c", m.map[0][i][j]);
      else if (m.map[1][i][j] != ' ')
        mvwprintw(dungeon, i+1, j+1, "%c", m.map[1][i][j]);
      else
        mvwprintw(dungeon, i+1, j+1, "%c", m.map[2][i][j]);
    }
  }

  wrefresh(dungeon);
}

void update_datalog(string message, WINDOW *datalog)
{
  wclear(datalog);
  box(datalog, 0, 0);
  mvwprintw(datalog, 1, 1, message.c_str());
  wrefresh(datalog);
}

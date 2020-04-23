#include <ncurses.h>
#include <string>

#include "../include/main_game.h"

using namespace std;

void MainMenuInit()
{
  //create window for menu
  WINDOW * menu = newwin(10,22,0,0);
  box(menu, 0, 0);
  refresh();
  wrefresh(menu);
  string options[7] =
  {
    "Minesweeper Dungeon",
    "1) New game",
    "2) Load game",
    "3) Instruction",
    "4) Setting",
    "5) High score",
    "6) Quit"
  };
  //enable arrow keys
  keypad(menu, true);
  int input;
  int highlight = 1;
  //menu loop
  while (true)
  {
    for (int i=0;i<7;i++) //print menu
    {
      if (i == highlight)
        wattron(menu, A_REVERSE); //highlight current option
      mvwprintw(menu, i+1, 1, options[i].c_str());
      wattroff(menu, A_REVERSE);
    }
    wrefresh(menu); //update menu
    input = wgetch(menu);
    switch(input)
    {
      case KEY_UP:
        highlight--;
        if (highlight == 0) //cycle
          highlight = 6;
        break;
      case KEY_DOWN:
        highlight++;
        if (highlight == 7) //cycle
          highlight = 1;
        break;
      default:
        break;
    }
    if (input == 10) //press ENTER
      break;
  }
  switch (highlight)
  {
    case 1:
      MainGameInit();
      break;
    case 2:
      //load_game();
      break;
    case 3:
      //print_instruction();
      break;
    case 4:
      //setting_menu();
      break;
    case 5:
      //print_high_score();
      break;
    case 6:
      break;
  }
  mvwprintw(menu, 7+1, 1, "Program end");
  wgetch(menu);
}

#include <ncurses.h>
#include <string>

#include "../include/main_game.h"

using namespace std;

/////////////////////////////////////////////
//Private functions declaration

void InitMenuDisplay(WINDOW *&menu);
int NavigateMenu(WINDOW *menu);
void MenuOption(int option);


/////////////////////////////////////////////
//Functions

void MainMenuInit() {
  int menu_input;
  WINDOW *menu;

  //init config manu display
  InitMenuDisplay(menu);
  
  //Get GUI user input
  menu_input = NavigateMenu(menu);
  
  //Execute cooresponding input
  MenuOption(menu_input);


  //testing notes
  mvwprintw(menu, 7+1, 1, "Program end");
  wgetch(menu);
}


/////////////////////////////////////////////
//Private functions

void InitMenuDisplay(WINDOW *&menu) {

  menu = newwin(10,22,0,0);
  //create window for menu
  box(menu, 0, 0);
  refresh();
  wrefresh(menu);

  //enable arrow keys
  keypad(menu, true);
}


int NavigateMenu(WINDOW *menu) {
  int input;
  int highlight = 1;

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
  
  //menu loop
  while (input != 10){    //NOT press ENTER

    for (int i=0;i<7;i++) { //print menu
      if (i == highlight) {
        wattron(menu, A_REVERSE); //highlight current option
      }

      mvwprintw(menu, i+1, 1, options[i].c_str());
      wattroff(menu, A_REVERSE);

    }

    wrefresh(menu); //update menu
    input = wgetch(menu);

    switch(input) {
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
    
  }

  return highlight;
}


void MenuOption(int option) {
  switch (option) {
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

}



#include <ncurses.h>
#include "../include/menu.h"

int main(){
  //initialize ncurses screen
  initscr();
  //user input doesn't print on screen
  noecho();
  /*press ctrl+c to break the program
   without closing the terminal*/
  cbreak();
  //Initialize menu
  MainMenuInit();
  //clear ncurses data structure
  endwin();

  return (0);
}

#include <ncurses.h>

#include "../include/menu.h"

void Gameover();

void MainGameInit()
{
  clear();
  getch();
  Gameover();
}

void Gameover()
{
  MainMenuInit();
}

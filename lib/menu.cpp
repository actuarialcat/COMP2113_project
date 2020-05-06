#include <iostream>
#include <iomanip>
#include <string>

#include "../include/main_game.h"

using namespace std;

/////////////////////////////////////////////
//Private functions declaration

void MenuDisplay(int highlight);
int NavigateMenu();
void MenuOption(int option);


/////////////////////////////////////////////
//Functions

void MainMenuInit() {
  int menu_input;
  //Get GUI user input
  menu_input = NavigateMenu();
  //Execute cooresponding input
  MenuOption(menu_input);
}


/////////////////////////////////////////////
//Private functions

void MenuDisplay(int highlight){
  //clear screen
  for (int i=0;i<30;i++){
    cout << endl;
  }
  //set width and height
  const int height = 9;
  const int width = 30;
  //print upper border
  for (int i=0;i<width+2;i++){
    cout << "-";
  }
  cout << endl;
  //print content
  string options[9] =
  {
    "Minesweeper Dungeon",
    "1) New game",
    "2) Load game",
    "3) Instruction",
    "4) Setting",
    "5) High score",
    "6) Quit",
    "Press w/s to scroll up/down",
    "Press y to confirm option"
  };
  cout << left;
  for (int i=0;i<height;i++){
    cout << "|";
    if (i == highlight){
      cout << setw(width) << options[i] + "<--";
    } else {
      cout << setw(width) << options[i];
    }
    cout << "|" << endl;
  }
  //print lower border
  for (int i=0;i<width+2;i++){
    cout << "-";
  }
  cout << endl;
}


int NavigateMenu() {
  char input;
  int highlight = 1;
  //menu loop
  MenuDisplay(highlight);
  cin >> input;
  while (input != 'y'){ //replace ENTER
    if (input == 'w'){
      if (highlight == 1){
        highlight = 6;
      } else {
        highlight--;
      }
    } else if (input == 's'){
      if (highlight == 6){
        highlight = 1;
      } else {
        highlight++;
      }
    }
    MenuDisplay(highlight);
    cin >> input;
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

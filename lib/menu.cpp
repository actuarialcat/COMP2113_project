#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

#include "../include/main_game.h"

using namespace std;

/////////////////////////////////////////////
//Private functions declaration

void MenuDisplay(int highlight);
int NavigateMenu();
void MenuOption(int option);
void print_high_score();


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
  //replace ENTER with 'y' key
  while (input != 'y'){
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
      print_high_score();
      break;

    case 6:
      break;

  }

}

void print_high_score(){
  //clear screen
  for (int i=0;i<50;i++){
    cout << endl;
  }
  cout << "//Highscores//" << endl;
  //open Highscore.txt
  ifstream fin("Highscore.txt");
  if (fin.fail()){exit(1);}
  string name, score;
  int i = 0;
  //some fake values written mannually for testing
  while (fin >> name){
    i++;
    if (i == 1){
      cout << "1st ";
    } else if (i == 2){
      cout << "2nd ";
    } else if (i == 3){
      cout << "3rd ";
    } else {
      cout << to_string(i) << "th ";
    }
    cout << left << setw(8) << name;
    fin >> score;
    cout << right << setw(8) << score << endl;
  }
  fin.close();
  cout << "Press any key to go back to the main menu." << endl;
  char input;
  cin >> input;
  MainMenuInit();
}

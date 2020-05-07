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
  const int height = 8;
  const int width = 30;

  //print upper border
  for (int i=0;i<width+2;i++){
    cout << "-";
  }

  cout << endl;
  //print content
  string options[8] =
  {
    "     Minesweeper Dungeon",
    "",
    "1) New game",
    "2) Leaderboard",
    "3) Quit",
    "",
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
  int highlight = 2;
  //menu loop
  MenuDisplay(highlight);
  cin >> input;
  //replace ENTER with 'y' key
  while (input != 'y'){
    if (input == 'w'){
      if (highlight == 2){
        highlight = 4;
      } else {
        highlight--;
      }
    } else if (input == 's'){
      if (highlight == 4){
        highlight = 2;
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
    case 2:
      MainGameInit();
      break;

    case 3:
      print_high_score();
      break;

    case 4:
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

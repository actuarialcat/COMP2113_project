#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <map>
#include <vector>
#include <bits/stdc++.h>

#include "../include/menu.h"
#include "../include/Character.h"
#include "../include/Map.h"
#include "../include/game_display.h"

using namespace std;

/////////////////////////////////////////////
//private functions declaration

void reveal_starting_map(Character &p, Map &m);
bool check_boundary_condition(int x, int y, Map m);

void GameLoop(Character &p, Map &m, string message[]);
bool check_not_end_game(Character p);
void reveal_map(Character &p, Map &m, int move_target_x, int move_target_y);

int MoveInput(int &move_target_x, int &move_target_y);

//Manu Logic
void Gameover(int final_score);

void test_mode(Character &p, Map &m);

/////////////////////////////////////////////


/////////////////////////////////////////////

//Game Initialization
void MainGameInit(){
  //clear screen
  for (int i=0;i<50;i++){
    cout << endl;
  }
  //doom mode determination
  cout << "Would you like to activate the doom mode?(y/n)" << endl;
  cout << "(number tile will no longer exceed '3' when" << endl;
  cout << "there are more than 3 enemies in the surroundings)" << endl;
  char doom_mode;
  cin >> doom_mode;

  //init map size
  int height, width;
  height = 10;
  width = 20;

  //Init character
  Character p('@');

  //Init Map
  Map m(height, width, p.flr, doom_mode);
  p.num_of_enemy = m.num_of_enemy;
  reveal_starting_map(p, m);

  //Init message
  /*
  first line of message: tell player what happen
  e.g. You encountered an enemy!
  seocnd line of message: display data change
  e.g. You lost 9 hp
  */
  string message[2] = {"You entered the 1st floor of the dungeon.",
   "Press w/a/s/d to move"};

  //start game
  GameLoop(p, m, message);

  //End game
  Gameover(p.score);
  m.deleteAll();

  MainMenuInit();
}

//--------------------------------------------

void reveal_starting_map(Character &p, Map &m) {
  for (int i=-1;i<=1;i++){
    for (int j=-1;j<=1;j++){
      //check boundary condition
      if (check_boundary_condition(p.x+j, p.y+i, m)){
        m.discovery_layer[p.y+i][p.x+j] = ' ';
      }
    }
  }
}

bool check_boundary_condition(int x, int y, Map m) {
  if (y >= 0 && y < m.height && x >= 0 && x < m.width){
    return true;
  }
  else {
    return false;
  }
}

/////////////////////////////////////////////
//Game Logic

void GameLoop(Character &p, Map &m, string message[]){
  int move_target_x, move_target_y;

  while(check_not_end_game(p)){
    move_target_x = p.x;
    move_target_y = p.y;

    //display everything
    GameDisplay(p, m, message);

    //control input
    int code = MoveInput(move_target_x, move_target_y);

    if(code == 0){
      if (check_boundary_condition(move_target_x, move_target_y, m)) {
        reveal_map(p, m, move_target_x, move_target_y);

        //collision check and pre-move interaction
        if( m.object_layer[move_target_y][move_target_x]->collisionCheck(p, message) ){
          p.y = move_target_y;    //moving
          p.x = move_target_x;

          if(m.object_layer[p.y][p.x]->postMoveAction(p, message)){   //post move interaction
            m.removeMapObject(p.x, p.y);
          }
        }
      }
      else {
        message[0] = "This is the edge of the dungeon.";
        message[1] = "";
      }
    }
    else if (code == 1){
        test_mode(p, m);
    }
  }


}

//---------------------------------------------

bool check_not_end_game(Character p){
  if (p.hp > 0) {return true; }

  return false;
}

void reveal_map(Character &p, Map &m, int dst_x, int dst_y){
  if (m.discovery_layer[dst_y][dst_x] == '?'){
      m.discovery_layer[dst_y][dst_x] = ' ';
      p.score++;
  }
}


//Get user GUI input
int MoveInput(int &move_target_x, int &move_target_y) {
  bool valid;
  char input;
  int code = 0;

  while(!valid){
    std::cin >> input;

    valid = true;
    switch(input) {
      case 'w':
        move_target_y--;
        break;

      case 's':
        move_target_y++;
        break;

      case 'a':
        move_target_x--;
        break;

      case 'd':
        move_target_x++;
        break;

      case '@':
        code = 1;   //test mode
        break;

      /*call game pause manu;
      case :
        break;
      */
      default:
        valid = false;
        break;
    }
  }

  return code;
}

/////////////////////////////////////////////

void test_mode(Character &p, Map &m){
  string inp;
  int arg = 0;

  std::cin >> inp;
  if(inp != "reveal"){ std::cin >> arg; }

  if(inp == "reveal"){
    for (int i = 0; i < m.height; i++) {
      for (int j = 0; j < m.width; j++) {
        m.discovery_layer[i][j] = ' ';
      }
    }
  }
  else if(inp == "lvl"){
    p.lv = arg;
  }
  else if(inp == "expr"){
    p.expr = arg;
  }
  else if(inp == "max_hp"){
    p.max_hp = arg;
  }
  else if(inp == "hp"){
   p.hp = arg;
  }
  else if(inp == "x"){
    p.x = arg;
  }
  else if(inp == "y"){
    p.y = arg;
  }
  else if(inp == "floor"){
    p.flr = arg;
  }
  else if(inp == "score"){
    p.score = arg;
  }
}



/////////////////////////////////////////////
//Manu Logic

void Gameover(int final_score)
{
  //Gameove message
  cout << "Gameover" << endl;
  cout << "Your final score is " << final_score << endl;
  cout << "Please input for name: (no more than 8 characters)" << endl;
  string this_game_name;
  cin >> this_game_name;
  //create a dictionary
  map<int, string> leaderboard;
  leaderboard[final_score] = this_game_name;
  vector<int> list_of_score;
  list_of_score.push_back(final_score);
  //get data from Highscore.txt
  ifstream fin("Highscore.txt");
  if (fin.fail()){exit(1);}

  string name;
  int score;
  while (fin >> name){
    fin >> score;
    leaderboard[score] = name;
    list_of_score.push_back(score);
  }
  fin.close();
  //sort list_of_score in descending order
  sort(list_of_score.begin(), list_of_score.end(), greater<int>());
  //rewrite Highscore.txt
  ofstream fout("Highscore.txt");
  if (fout.fail()){exit(1);}
  for (int i=0;i<list_of_score.size();i++){
    //only store the best 10 records
    if (i < 10){
      fout << leaderboard[list_of_score[i]] << " " << list_of_score[i] << endl;
    }
  }
  fout.close();
  //Back to Main Menu
  cout << "Press any key to go back to Main Menu." << endl;
  char input;
  cin >> input;
}

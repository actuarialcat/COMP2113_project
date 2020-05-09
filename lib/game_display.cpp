#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

#include "../include/Character.h"
#include "../include/Map.h"
#include "../include/game_object.h"
#include "../include/game_display.h"
/////////////////////////////////////////////

void print_dungeon(Character p, Map m);
void print_stats(Character p, Map m);
/////////////////////////////////////////////

void GameDisplay(Character p, Map m, string *message){

  //clear screen
  for (int i=0;i<50;i++){
    cout << endl;
  }

  //print dungeon
  print_dungeon(p, m);

  //print message
  cout << message[0] << endl;
  cout << message[1] << endl;

  //print stats
  print_stats(p, m);

}
void print_dungeon(Character p, Map m){

  //upper border of map
  for (int i=0;i<m.width+2;i++){
    cout << "-";
  }
  cout << endl;

  //content of the map
  for (int i=0;i<m.height;i++){
    cout << "|";
    for (int j=0;j<m.width;j++){

      //display player
      if (i == p.y && j == p.x){
        cout << p.symbol;
      } else {

        //displayer std::map<key, value> map;
        if (m.discovery_layer[i][j] != ' '){
          cout << m.discovery_layer[i][j];
        } else if (m.object_layer[i][j]->getDisplayChar() != ' '){
          cout << m.object_layer[i][j]->getDisplayChar();
        } else {
          cout << m.number_layer[i][j];
        }
      }
    }
    cout << "|" << endl;
  }

  //lower border of map
  for (int i=0;i<m.width+2;i++){
    cout << "-";
  }
  cout << endl;

}

void print_stats(Character p, Map m){
  //doom mode
  cout << endl;
  if (p.doom_mode == true){
    cout << "\"Doom Mode\"" << endl;
  } else {
    cout << "\"Normal Mode\"" << endl;
  }

  
  cout << "Floor " << p.flr << endl;
  cout << "Hidden enemies: " << p.num_of_enemy << endl;
  cout << "Hp " << p.hp << "/" << p.max_hp << endl;
  cout << "Score " << p.score << endl;
}

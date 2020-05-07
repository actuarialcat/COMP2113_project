#ifndef MAP_H
#define MAP_H

#include <vector>

#include "../include/game_object.h"

using namespace std;

/////////////////////////////////////////////

class Map
{
public:
  //variable
  int height, width, floor;
  int num_of_enemy;
  /*
  Init 3 layers 2d map
  upper layer: ? layer
  middle layer: game objects layer
  lower layer: number layer
  */
  vector<vector<char>> discovery_layer;
  vector<vector<GameObjectBase *>> object_layer;
  vector<vector<char>> number_layer;

  //functions
  Map(int h, int w, int floor);
  //~Map();

private:
  //variable
  GameObjectBase *wall_ptr, *floor_ptr;

  //functions
  void placeEnemyRandom(int num_of_enemy, int floor);
  void placePotion(int num_large_potion, int num_small_potion);

  int findRandom(int &randy, int &randx);

  void generateNumberLayer();
  void generateDiscoveryLayer();


};



#endif

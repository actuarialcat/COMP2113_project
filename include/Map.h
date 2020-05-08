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
  bool doom_mode;
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
  Map(int h, int w, int floor, bool init_doom_mode);
  ~Map();

  void deleteAll();
  void removeMapObject(int x, int y);

private:
  //variable
  GameObjectBase *wall_ptr, *floor_ptr;

  //functions
  void placeEnemyRandom(int num_of_enemy, int floor);
  void placePotion(int num_large_potion, int num_small_potion);
  void placeHealthGem(int num_large_gem, int num_small_gem);
  void placeTreasure(int num_large_treasure, int num_small_treasure);
  void placeStair(int num_stair, int floor);

  int findRandom(int &randy, int &randx);

  void generateNumberLayer();
  void generateDiscoveryLayer();


};



#endif

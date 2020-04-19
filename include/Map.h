#include <vector>
using namespace std;

#ifndef MAP_H
#define MAP_H

class Map
{
public:
  int height, width;
  int flr;
  /*
  Init 3 layers 2d map
  upper layer: ? layer
  middle layer: game objects layer
  lower layer: number layer
  */
  vector<vector<vector<char>>> map;
  Map(int h, int w, int flr);
  void generate();
};
#endif

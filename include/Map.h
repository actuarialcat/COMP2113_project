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
  1st layer: ? layer
  2nd layer: game objects layer
  3rd layer: number layer
  */
  vector<vector<vector<char>>> map;
  Map(int height, int width, int flr);
};
#endif

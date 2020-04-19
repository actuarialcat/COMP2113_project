#include <vector>

#include "../include/Map.h"

Map::Map(int height, int width, int flr)
{
  height = height;
  width = width;
  flr = flr;
  vector<vector<vector<char>>> map2(3, vector<vector<char>>(height, vector<char>(width, '2')));
  map = map2;
}

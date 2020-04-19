#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

#include "../include/Map.h"

Map::Map(int h, int w, int flr)
{
  height = h;
  width = w;
  flr = flr;
  vector<vector<vector<char>>> map2(
    3, vector<vector<char>>(height, vector<char>(width, ' ')));
  map = map2;
}
void Map::generate()
{
  srand(time(NULL));
  map[1][2][3] = 'E';
  //distribute monsters on the middle layer
  int monsters = 40; //more monsters on higher floor
  while(monsters > 0)
  {
    int randy = rand() % height;
    int randx = rand() % width;
    if (map[1][randy][randx] == ' ')
    {
      map[1][randy][randx] = 'E';
      monsters--;
    }
  }
  //assign number on the lowest number layers
  for (int i=0;i<height;i++)
  {
    for (int j=0;j<width;j++)
    {
      int count = 0;
      //check for surrounding 8 tiles
      for (int k=-1; k<2;k++)
      {
        for (int l=-1; l<2;l++)
        {
          //check boundaries condition
          if (k == 0 && l == 0)
            continue;
          if (i+k == -1 || i+k == height)
            continue;
          if (j+l == -1 || j+l == width)
            continue;
          if (map[1][i+k][j+l] == 'E')
            count++;
        }
      }
      map[2][i][j] = 48 + count;
    }
  }
  //the upper layer covered with ?
  for (int i=0;i<height;i++)
  {
    for (int j=0;j<width;j++)
    {
      map[0][i][j] = '?';
    }
  }
}

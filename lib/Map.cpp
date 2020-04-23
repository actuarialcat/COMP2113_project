#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

#include "../include/Map.h"
#include "../include/game_object.h"

/////////////////////////////////////////////

Map::Map(int h, int w, int flr)
{
  height = h;
  width = w;
  floor = flr;

  //common pointer for deuplicative static objects
  wall_ptr = new ObjectWall('W');
  floor_ptr = new ObjectFloor(' ');

  vector<vector<char>> null_char_map(height, vector<char>(width, ' '));
  discovery_layer = null_char_map;
  number_layer = null_char_map;

  vector<vector<GameObjectBase *>> null_object_map(height, vector<GameObjectBase *>(width, floor_ptr));
  object_layer = null_object_map;


  //Generate each layer
  int num_of_enemy = 40; //depending on floor?

  placeEnemyRandom(num_of_enemy);
  generateNumberLayer();
  generateDiscoveryLayer();

}

/////////////////////////////////////////////

void Map::placeEnemyRandom(int num_of_enemy){
  srand(time(NULL));

  //randomly place enemy
  while(num_of_enemy > 0) {
    int randy = rand() % height;
    int randx = rand() % width;
    
    if (object_layer[randy][randx] == floor_ptr) {
      object_layer[randy][randx] = new ObjectEnemy('E', 10);
      num_of_enemy--;
    }
  }
  
}


void Map::generateNumberLayer(){
  //assign number on the number layer
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
          if (object_layer[i+k][j+l]->getDisplayChar() == 'E')
            count++;
        }
      }
      number_layer[i][j] = '0' + count;
    }
  }

}


void Map::generateDiscoveryLayer(){
  //the discovery layer covered with ?
  for (int i=0;i<height;i++)
  {
    for (int j=0;j<width;j++)
    {
      discovery_layer[i][j] = '?';
    }
  }

}

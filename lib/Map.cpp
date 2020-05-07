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
  num_of_enemy = h*w*0.2 + flr*5; //depending on floor
  
  const int num_large_potion = 5;
  const int num_small_potion = 5;
  const int num_large_gem = 5;
  const int num_small_gem = 5;
  const int num_large_treasure = 5;
  const int num_small_treasure = 5;

  //common pointer for deuplicative static objects
  wall_ptr = new ObjectWall('W');
  floor_ptr = new ObjectFloor(' ');

  vector<vector<char>> null_char_map(height, vector<char>(width, ' '));
  discovery_layer = null_char_map;
  number_layer = null_char_map;

  vector<vector<GameObjectBase *>> null_object_map(height, vector<GameObjectBase *>(width, floor_ptr));
  object_layer = null_object_map;


  //Generate each layer
  srand(time(NULL)); 
  placeEnemyRandom(num_of_enemy, floor);
  placePotion(num_large_potion, num_small_potion);
  placeHealthGem(num_large_gem, num_small_gem);
  placeTreasure(num_large_treasure, num_small_treasure);

  generateNumberLayer();
  generateDiscoveryLayer();

}


Map::~Map() {
  //Don't know why doesn't work
}


void Map::deleteAll() {
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      if(object_layer[i][j] != floor_ptr && object_layer[i][j] != wall_ptr){
        delete object_layer[i][j];
      }
    }
  }
  
  delete wall_ptr;
  delete floor_ptr;
}

void Map::removeMapObject(int x, int y) {
  delete object_layer[y][x];
  object_layer[y][x] = floor_ptr;
}


/////////////////////////////////////////////

void Map::placeEnemyRandom(int num_of_enemy, int floor){
  int randy, randx;

  for (int i = 0; i < num_of_enemy; i++ ) {
    findRandom(randy, randx);
    object_layer[randy][randx] = new ObjectEnemy('E', floor);
  }
}

void Map::placePotion(int num_large_potion, int num_small_potion){
  int randy, randx;

  for (int i = 0; i < num_large_potion; i++ ) {
    findRandom(randy, randx);
    object_layer[randy][randx] = new ObjectPotion('P', 2);
  }

  for (int i = 0; i < num_small_potion; i++ ) {
    findRandom(randy, randx);
    object_layer[randy][randx] = new ObjectPotion('p', 1);
  }
}

void Map::placeHealthGem(int num_large_gem, int num_small_gem){
  int randy, randx;

  for (int i = 0; i < num_large_gem; i++ ) {
    findRandom(randy, randx);
    object_layer[randy][randx] = new ObjectHealthGem('G', 2);
  }

  for (int i = 0; i < num_small_gem; i++ ) {
    findRandom(randy, randx);
    object_layer[randy][randx] = new ObjectHealthGem('g', 1);
  }
}

void Map::placeTreasure(int num_large_treasure, int num_small_treasure){
  int randy, randx;

  for (int i = 0; i < num_large_treasure; i++ ) {
    findRandom(randy, randx);
    object_layer[randy][randx] = new ObjectTreasure('T', 2);
  }

  for (int i = 0; i < num_small_treasure; i++ ) {
    findRandom(randy, randx);
    object_layer[randy][randx] = new ObjectTreasure('t', 1);
  }
}

int Map::findRandom(int &randy, int &randx) {
  int i = 0;
  do{
    randy = rand() % (height);    // no objects in starting area
    randx = rand() % (width);
    i++;
  } while(((randy < 2 && randx < 2) || object_layer[randy][randx] != floor_ptr) && i < 10000);

  if (i == 10000){throw "No free place";}
  return 0;
}

//---------------------------------------------

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

//Menu Game Functions

//****************************** Header Libraries

#include <iostream>
#include "../include/main_game.h"
#include "../include/display.h"
#include "../include/game_object.h"

//****************************** Structures

//****************************** Global Variables

using namespace std;

//****************************** Function prototypes

void MainGameLoop(MapClass *map, PlayerClass *player);
void move_player(int x, int y);
bool collision_check();

//****************************** Public Functions

void MainGameInit() {

    MapClass *map = new MapClass();
    PlayerClass *player = new PlayerClass();
    
    MainGameLoop(map, player);

}

//****************************** Private Functions

void MainGameLoop(MapClass *map, PlayerClass *player) {
    bool end_game = 0;

    while (!end_game) {
        int inp;

        //Display map

        //control input
    
        switch (inp) {
            case 1:
                //save_game
                break;    
            case 2:
                move_player(0,1);
                break;
        }

        //check end game
    }
}

void move_player(int x, int y) {

    //collision check
    if (collision_check()) {
        //pre-move action
    }
    else {
        //post-move action
    }
}

bool collision_check() {
    return (0);
}

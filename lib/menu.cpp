//Menu Functions

#include <iostream>
#include "../include/menu.h"
#include "../include/display.h"
#include "../include/main_game.h"

using namespace std;

void MainMenuInit() {
    int inp, exit = 0;

    //display menu
    cout << "Hello World!" << endl;
    //call display functions

    //Main menu
    while (!exit){
        //Menu Input
        cin >> inp;

        //Flow control
        switch (inp){
            case 1:
                //call respective function
            break;
        }
    }
}



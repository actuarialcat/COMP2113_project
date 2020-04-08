//Menu Functions

//****************************** Header Libraries

#include <iostream>
#include "../include/menu.h"
#include "../include/display.h"
#include "../include/main_game.h"

//****************************** Structures

//****************************** Global Variables

using namespace std;

//****************************** Function prototypes

void DisplayMainMenu();

void GameMenu();
void DisplayGameMenu();

void SettingMenu();
void DisplaySettingMenu();


//****************************** Public Functions

void MainMenuInit() {
    int inp, exit = 0;

    //Main program loop
    while (!exit){
        //display menu
        DisplayMainMenu();

        //menu input
        //inp = Menu_input();

        //Flow control
        switch (inp){
            case 1:
                //call respective function
            break;
        }
    }
}


//****************************** Private Functions

void DisplayMainMenu() {
    //display the main menu

    //use functions in display.h
}


//****************************** 

void GameMenu() {
    int inp;

    //display menu
    DisplaySettingMenu();

    //menu input
    //inp = Menu_input();

    //Flow control
    switch (inp){
        case 1:
            //MainGameInit()
        break;
    }
}

void DisplayGameMenu() {
    //display the main menu

    //use functions in display.h
}

//****************************** 

void SettingMenu() {
    int inp;

    //display menu
    DisplaySettingMenu();

    //menu input
    //np = Menu_input();

    //Flow control
    switch (inp){
        case 1:
            //call respective function
        break;
    }
}

void DisplaySettingMenu() {
    //display the main menu

    //use functions in display.h
}


//****************************** 







//****************************** 

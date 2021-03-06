# Minesweeper Dungeon
COMP 2113 Course Project

## Brief identification of the team members

Jackson Leung  
Fong Cheuk Ting 

## Game description
Minesweeper Dungeon is a rougue-like RPG combined with minsweeper. You are a the most greedy treasure seeker in the world who sneak into a treasure dungeon overwhelmed with dangerous monsters to gather as much treasure as possible. You have the amazing "minesweeper" ability to sense the presence of surroundings' ememies. Use this power wisely to avoid encountering monsters as much as possible. There are also special items inside the dungeon which helps you survived longer.

Player start on 1st floor with 30 health. Everytime you enter a new floor, every tile except 3x3 area of your starting location will be "?". Unlike traditional minsweeper game where you can click any tile you wish, treasure seeker doesn't have the ability of teleport. You can only reveal and move to the 4 tiles next your current position by pressing w/a/s/d key. Whenever you reveal a "?" tile, there are three basic possible outcome:

1)empty tile: nothing will happen  
2)monster tile: a monster immediately ambush you, losing decent amount of hp  
3)items tile: an items (e.g. hp potion, treasure chest) will appear on the tile, you can press the same key again to obtain it  

After a tile become an empty tile, a number ranged from 0 to 8 will appear on the tile to indicate the number of surroundings' enemies. Player can only move to a number tile.

Legend has it that the dungeon has infinite floor, your goal is collect as much treasure as possible before running out of hp.  


## How to use
### Compiling

The makefile provided will handle the compilation of the whole program. Just use the following command.

`make main`

For clean compiling use the following:

`make -B main`


### Starting

To run the game, execute the outputed program "main". Or use the following command.

`make run`

### Interacting with the game

To input commands into the game, type a single letter command then press "enter". (This is a limiation due to `<iostream>`)
In-game instruction will provide the description of the commands available.

TIP: Remeber to press "enter"

### Test mode

When playing the game, the following test mode commands are available.
Enter the commands in such format. (Remeber to start with "@").

`@<function> <arg>`

| Function            | Description |
|---------------------|-------------|
| reveal              | Reveal the entire map. No arguments. |
| hp                  | Set the current player hp to `<arg>`. |
| max_hp              | Set the maximum player hp to `<arg>`. |
| x                   | Set the player's x-coordinates to `<arg>`. |
| y                   | Set the player's y-coordinates to `<arg>`. |
| floor               | Set the current floor to `<arg>`. Will not affect current the level. Only affect the next level. |
| score               | Set the current player score to `<arg>`. |


## Requirements Mapping
The following table show the mapping between our features and coding requirement 1-5.

| Features            | Requirement | Description   | Code           |
|---------------------|:-----------:|---------------|----------------|
| Level generation    |      1      | Enemies, power-ups and other objects will be place randomly when generating a new level. | Map.cpp function "findRandom" (line 145-155) generate the random location to place new objects. |
| Combat damage       |      1      | Combat damage taken by the plater when encountering enemies will be randomized. | Game_object.cpp ObjectEnemy member function "Dice" (line 64-71) generate random damage for combat. |
| Game objects        |     2, 3    | Enemies, power-ups, .etc will be stored as instance objects of the corresponding class, create or removed when necessary. <br> (See "Game Map" below) | GameObject.cpp and Map.cpp | 
| High Score          |      4      | High scores after completing a game will be saved inside a text file. The program can read from the file for high scores in previous attempts. | menu.cpp function "print_high_score" (line 129-161) and main_game.cpp function "Gameover" (line 313-361) |
| Modular programming |      5      | Modules are kepped in a mulitple files. <br> (See dependant graph below) | / |


## Main Program Design

### Global Struture
This chart shows the global structure of our program. It include a main game loop, in which the test mode can be accessed. It also includes a highscore page.

![global structure chart](/charts/Global_Structure.png)


### Game flowchart
This chart show the flowchart for the main game loop. It summarize the logic of program when main game is running.

![global structure chart](/charts/main_game_flowchart.png)


### Game map
The game map is created using a Map object. The Map object include a 2-D pointer array which points to the corresponding "game object" in each coordinate space. For example, if (1,1) should have a enemy, the [1][1] element of the array will point to a dynamically created object belonging to the class Enemy. The map object also include methods to populate the map with "game objects" during initizliation and methods to delete a specific object after it is removed from play (e.g. enemy is killed, potion is used, etc.).

"Game object" is a family of classes. The base class is GameObjectBase. This class provide the general method and attributes which all "Game object" use to interact with the game. It provide a constructor and 3 methods: a getter method to the display character (i.e. how to display this object), a collision check method (i.e. what to do when the player want to move into this object, can the player move?), and a post movement interaction method (i.e. what happen after the player successfully move on top of this object).

All of the "Game object" are inherited from GameObjectBase class. This include enemies, potions, treasures etc. Each child class will have addtional private methods and attributes to facilitate programming the collision check method and the post movement interaction.

Moreover, note that some objects which is static in nature (e.g. empty floor) are only created once. The the map pointers in various coordinate only points to the same object to save memory space.

The purpose of such programming architecture is that it can provide a uniform interface between the player object and all type of "Game object" (include new ones to be added in the future).

This chart show the objects used to fill up the Map.

![global structure chart](/charts/main_game_objects.png)


### Modules dependant graph
This chart shows the hierarchy structure between the files. It also shows the purpose of each file.

![global structure chart](/charts/dependant_graph.png)






## All Features
### Menus
User-friendly menus to navigate the functions of the program. Menu pages include:
* Main menu
* Leaderboard page
* A hidden test-mode page

### Main Game
#### Player attribute

int max_hp; //maximum hp you can have  
int hp; //gameover when health reduced to 0  
int floor, x, y; //position of player in the dungeon  
int score; //Your current score  
#### Encounters
'E' //lose health when encounters, amount of health loss will be calculating by throwing m n-face dice such the the damage is normally distributed  
'p' //lesser healing potion, heal for a small percentage of hp  
'P' //greater healing potion, heal for a large percentage of hp  
'g' //lesser health gem, increase max_hp by 3  
'G' //greater health gem, increase max_hp by 6  
't' //mini treasure chest, gain a small amount of score
'T' //treasure chest, gain a large amount of score  
'U' //staircase to the next floor

#### Doom mode
For player who love challenge, you may choose to activate doom mode at the start of a new game. In this mode, number tile which is supposed to be larger than '3' will become '3'. Making it harder for player to avoid monsters.  

#### Score system
Player will gain or lose score when they achieve certain progress in the game. It means to let player challenge themselves for getting the highest score possible.

1) reveal a tile: +1  
2) kill a monster: +10  
3) get a treasure chest: +20/+50  
4) pass a floor: + 100  
5) doom mode: final score multiply by 2!  
### High Score
Save highscore once a game is completed. Sorting algorithm is used here.

### Test Mode
Special features and cheats for quick testing of the game


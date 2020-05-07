# COMP2113_project
COMP 2113 Project for Group 225

## Brief identification of the team members

Fong Cheuk Ting, u3035688784  
Leung Chak Sum, 3035470905  
*Important!!! The contribution graph is messed up. Fong Cheuk Ting's contribution should minus 10082 lines.*
## Game description
Minesweeper Dungeon is a rougue-like RPG combined with minsweeper. You are a the most greedy treasure seeker in the world who sneak into a treasure dungeon overwhelmed with dangerous monsters to gather as much treasure as possible. You have the amazing "minesweeper" ability to sense the presence of surroundings' ememies. Use this power wisely to avoid encountering monsters as much as possible. There are also special items inside the dungeon which helps you survived longer.

Player start on 1st floor with 30 health. Everytime you enter a new floor, every tile except 3x3 area of your starting location will be "?". Unlike traditional minsweeper game where you can click any tile you wish, treasure seeker doesn't have the ability of teleport. You can only reveal and move to the 4 tiles next your current position by pressing w/a/s/d key. Whenever you reveal a "?" tile, there are three basic possible outcome:

1)empty tile: nothing will happen  
2)monster tile: a monster immediately ambush you, losing decent amount of hp  
3)items tile: an items (e.g. hp potion, treasure chest) will appear on the tile, you can press the same key again to obtain it  

After a tile become an empty tile, a number ranged from 0 to 8 will appear on the tile to indicate the number of surroundings' enemies. Player can only move to a number tile.

Legend has it that the dungeon has infinite floor, your goal is collect as much treasure as possible before running out of hp.  
## Requirements Mapping
The following table show the mapping between our features and coding requirement 1-5.

| Feature             | Requirement | Description |
|---------------------|:-----------:|-------------|
| Level generation    |      1      | Enemies, power-ups and other objects will be place randomly when generating a new level. |
| Combat event        |      1      | Combat damage will include a random element. |
| Game objects        |     2, 3    | Enemies, power-ups, .etc will be stored as instance objects of the corresponding class, create or removed when necessary.<br>(e.g Delete when enemy is killed) |
| Save game           |      4      | Game can be saved in at any time. It is saved using files. |
| High Score          |      4      | High score can be save to and read from a file. |
| Modular programming |      5      | Each module will be contained in a separate file. |

## Features
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

### High Score
Save highscore once a game is completed. Sorting algorithm is used here.

### Test Mode
Special features and cheats for quick testing of the game


## Design
Preliminary design as follows, subject to change.

### Global Struture

![global structure chart](/charts/Global_Structure.png)


### Main Game

![global structure chart](/charts/main_game_flowchart.png)

![global structure chart](/charts/main_game_objects.png)







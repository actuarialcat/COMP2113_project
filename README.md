# COMP2113_project
COMP 2113 Project for Group 225

## Brief identification of the team members

Fong Cheuk Ting, u3035688784  
Leung Chak Sum, 3035470905

## Game description
Sweeper Dungeon is a rougue-like RPG combined with minsweeper. You are a treasure seeker who sneak into a 8 storey dungeon overwhelmed with dangerous monsters to steal the ultimate treasure at the top floor. You have the amazing "minesweeper" ability to sense the presence of surroundings' ememies. Use this power wisely to avoid encountering monsters as much as possible such that you won't run out of stamina before getting the ultimate treasure. There are also mysterious merchants and useful treasures scattered across the dungeon to help you survive till the end.

Player start on 1st floor with 30 health. Everytime you enter a new floor, every tile except your starting location will be "?". Unlike traditional minsweeper game where you can click any tile you wish, treasure seeker doesn't have the ability of teleport. You can only reveal and move to the 4 tiles next your current position by pressing up, down, left and right key. Whenever you reveal a "?" tile, there are three basic possible outcome:

1)empty tile: nothing will happen  
2)monster tile: a monster will appear on the tile that you must press the key one more time to combat with, then you will lose health  
3)items tile: an items (e.g. gold, potion, treasure box) will appear on the tile, you can press the key one more time to obtain it  

After a tile become an empty tile, a number ranged from 0 to 8 will appear on the tile to indicate the number of surroundings' enemies. Player can only move to a number tile.


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
* Instruction page
* Settings page
* High-score page
* A hidden test-mode page

### Main Game
#### Player attribute
int level; //increases hp and max_hp when level up  
int max_hp; //maximum hp you can have  
int hp; //gameover when health reduced to 0  
int floor, x, y; //position of player in the dungeon  
int gold; //amount of gold you have  
int exp; //experience needed to level up, gain experience from revealing tile  
int inventory[]; //an array to store your treasures  

#### Encounters
'E' //lose health when encounters, amount of health loss will be calculating by throwing m n-face dice such the the damage is normally distributed  
'p' //healing potion, heal for a small percentage of max_hp  
't' //treasure chest, get a random treasures, one treasure chest on every floor, passive treasure on odd floor, active treasure on even floor  
'g' //gold, get a random amount of gold, 3-5 piles per floor  
'M' //Always one merchant on each floor normally, when encounters, below message will be display:  
1)heal (?? gold)  //heal for decent percentage of health, ??gold because not decided yet  
2)random treasure 1 (?? gold)  
3)random treasure 2 (?? gold) 

#### Map features
'W' //impassible wall, surrounding the floor, no number reveal 
'\*' //impassible void, randomly generated on the floor with no number reveal   
* fixed: location determined during level design  
* (Later implemetation) random: need path finder function to make sure every other tile is reachable  
'U' //stair up to the next floor, randomly generated one per each floor  

#### Teasures
For treasures and doom mode events, we will eventually design more of them in the future. Their name will be designed in the future as well.
Before the game, player can choose from 3 starting treasure:  
1) heal for 10% of max_hp everytime you enter a new floor  
2) Press "B" to reveal the 8 tiles around you, destroy all monsters and items on these 8 tile (one use per floor)  
3) Press "T" to sacrifice one health for one gold (infinite use)  
Examples of treasures from treasure chests and merchants:  
1) jump to the next floor (one use only)
2) double your current max_hp  (repeatable treasure)  
3) everytime you enter a new floor, reveal 5 random empty tiles  
4) when receive fatal damage, destroy this treasure and heal to 50% of max_hp  
5) throw one less dice when calculate the damage  (repeatable treasure)  
6) merchant will offer 50% discount  
7) gain one health for every 5 moves  

#### (Later implemetation) Doom mode
Unlock after the first time finish the normal mode. In this mode, every floor will have a random negative event which make it harder for player to survive. 2 random events on 4th and 8th floor. Examples of negative event:  
1) 10 extra monsters on the floor  
2) tiles larger than '2' become '2'  
3) die instantly when you encounter the third monster  
4) when calculate damage taken, roll an extra 10 faces die  
5) tiles smaller than '1' become '1'  
6) after the 30th move, take 2 damages every move  
7) lose gold instead of gain gold when picking gold pile, double the number of gold piles on this floor
8) cannot move to the next floor until there are less than 10 '?' tiles on this floor  

#### Score system
Player will gain or lose score when they achieve certain progress in the game. It means to let player challenge themselves for getting the highest score possible.  
1) reveal a tile: +1  
2) encounter monster: -10  
3) get a treasure: +10  
4) pass a floor: +20  
5) get the ultimate treasure: +1000  
6) each hp and gold remained:+1  

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







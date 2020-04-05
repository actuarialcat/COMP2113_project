## Game description with basic game rules
Sweeper Dungeon is a rougue-like game combined with minsweeper. You are a treasure seeker who sneak into a 10 storey dungeon overwhelmed with dangerous monsters to steal the ultimate treasure at the top floor. You have the amazing "minesweeper" ability to sense the presence of surroundings'  ememies. Use this power wisely to avoid encountering monsters as much as possible such that you won't run out of stamina before getting the ultimate treasure. There are also mysterious merchants and useful treasures scattered across the dungeon to help you survive  till the end.

Everytime you enter a new floor, every tile except your starting location will be "?". Unlike traditional minsweeper game where you can click any tile you wish, treasure seeker doesn't have the ability of teleport. You can only reveal and move to the 4 tiles next your current position by pressing up, down, left and right key. Whenever you reveal a "?" tile, there are three basic possible outcome:  
1)empty tile: nothing will happen  
2)monster tile: a monster will appear on the tile that you must press the key one more time to combat with, then you will lose health  
3)items tile: an items (e.g. gold, potion, treasure box) will appear on the tile, you can press the key one more time to obtain it  
After a tile become an empty tile, a number ranged from 0 to 8 will appear on the tile to indicate the number of surroundings' enemies
## Features
### Champion attribute
int level; //increases hp and max_hp when level up
int max_hp; //maximum hp you can have
int hp; //gameover when health reduced to 0  
int floor, x, y; //position of player in the dungeon
int gold; //amount of gold you have  
int exp; //experience needed to level up  
int inventory[]; //an array to store your treasures
### Monsters attribute
int strength; //player loses health equal to its strength when encounters it

### Resources list
#### equipments 
#### health potions
'h': increases hp
#### special items
'p': pickaxe, used to break a wall
't': teleporter, teleport to the opposite side of the current floor w.r.t. the center
### Map features
#### Wall
'W': impassible tile, breakable with pickaxe
#### Void
'\*': impassible tile, unbreakable with pickaxe
#### Door
'Y': impassible tile, spend a yellow key to open  
'B': impassible tile, spend a blue key to open  
'R': impassible tile, spend a red key to open  
#### Stair
'U': floor up  
'D': floor down  
### rougelike mode
Monsters and resources are randomized across the tower
## Function
### Map and statistic display
### Battle damage calculator
### Merchent system, trade gold for stats
### Save/Load system
### Monsters and resources random generator for the rougelike mode

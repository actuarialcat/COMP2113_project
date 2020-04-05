## Game description with basic game rules
Sweeper Dungeon is a rougue-like game combined with minsweeper. You are a treasure seeker who sneak into a dungeon to steal the  
ultimate treasure overwhelmed with dangerous monsters. You have the amazing "minesweeper" ability to sense the presence of surroundings'  
ememies. Use this power wisely to avoid encountering monsters as much as possible such that you won't run out of stamina before  
getting the ultimate treasure. There are also mysterious merchants and useful treasures scattered around the dungeon to help you survive  
till the end.

Unlike traditional minsweeper game where you can click any tile you wish, treasure seek doesn't have the ability of teleport. You can only  
"click" the 
## Features
### Champion attribute
int level; //increases stats when level up  
int hp; //gameover when health reduced to 0  
int floor, x, y; //position of player in the tower  
int gold; //amount of gold you have  
int exp; //experience needed to level up  
int face; //the direction you are facing  
int yellow_key, blue_key, red_key; //number of keys in your inventory
int pickaxe, teleporter, ...; //number of special items in your inventory  
### Monsters attribute
int level; //indicate the strength of the enemy, useful in rougelike mode
int hp; //reduce its health to 0 to kill it  
int atk; //attack  
int def; //defence  
int gold; //gold gained from killing it  
int exp; //experience gained from killing it  

### Resources list
#### equipments
#### energy gems
'a': increases atk  
'd': increases def  
'm': increases mdef  
#### health potions
'h': increases hp
#### keys
'y': yellow key  
'b': blue key  
'r': red key  
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

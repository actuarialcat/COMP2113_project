## Game description with basic game rules
Sweeper Dungeon is a rougue-like RPG combined with minsweeper. You are a treasure seeker who sneak into a 8 storey dungeon overwhelmed with dangerous monsters to steal the ultimate treasure at the top floor. You have the amazing "minesweeper" ability to sense the presence of surroundings'  ememies. Use this power wisely to avoid encountering monsters as much as possible such that you won't run out of stamina before getting the ultimate treasure. There are also mysterious merchants and useful treasures scattered across the dungeon to help you survive  till the end.

Everytime you enter a new floor, every tile except your starting location will be "?". Unlike traditional minsweeper game where you can click any tile you wish, treasure seeker doesn't have the ability of teleport. You can only reveal and move to the 4 tiles next your current position by pressing up, down, left and right key. Whenever you reveal a "?" tile, there are three basic possible outcome:  

1)empty tile: nothing will happen  
2)monster tile: a monster will appear on the tile that you must press the key one more time to combat with, then you will lose health  
3)items tile: an items (e.g. gold, potion, treasure box) will appear on the tile, you can press the key one more time to obtain it  

After a tile become an empty tile, a number ranged from 0 to 8 will appear on the tile to indicate the number of surroundings' enemies
## Features
### Player
int level; //increases hp and max_hp when level up  
int max_hp; //maximum hp you can have  
int hp; //gameover when health reduced to 0  
int floor, x, y; //position of player in the dungeon  
int gold; //amount of gold you have  
int exp; //experience needed to level up, gain experience from revealing tile  
int inventory[]; //an array to store your treasures  
### Monsters
'E'; //lose health when encounters  
Amount of health loss will be calculating by throwing m n-face dice such the the damage is normally distributed  
### items
'p'; //healing potion, increases a nice percentage of hp  
't'; //treasure chest, get a random treasures, one treasure chest on every floor  
passive treasure on odd floor, active treasure on even floor  
'g'; //gold, get a random amount of gold, 3-5 piles per floor  
### Merchant
'M';Always one merchant on each floor normally, when encounters, below message will be display:  
1)heal (?? gold)  //heal for decent percentage of health, ??gold because not decided yet  
2)random treasure 1 (?? gold)  
3)random treasure 2 (?? gold) 
### Map features
'W': impassible wall, surrounding the floor, no number reveal
'\*': impassible void, randomly generated on the floor with no number reveal, 
'U': stair up to the next floor, randomly generated one per each floor  
### teasures
For treasures and doom mode events, we will eventually design more of them in the future. Their name will be designed in the future as well.
Before the game, player can choose from 3 starting treasure:  
1)heal for 10% of max_hp everytime you enter a new floor  
2)Press "B" to reveal the 8 tiles around you, destroy all monsters and items on these 8 tile (one use per floor)  
3)Press "T" to sacrifice one health for one gold (infinite use)  
Examples of treasures from treasure chests and merchants:  
1)jump to the next floor (one use only)
2)double your current max_hp  
3)everytime you enter a new floor, reveal 5 random empty tiles  
4)when receive fatal damage, destroy this treasure and heal to 50% of max_hp  
### doom mode
Unlock after the first time finish the normal mode. In this mode, every floor will have a random negative event make it harder for player to survive. Examples of negative event:  
1) 5/10/15 extra monsters  
2) tiles larger than '2' will become '2'  
3) die instantly when you encounter the third monster  

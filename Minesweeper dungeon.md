## Game description with basic game rules
Sweeper Dungeon is a rougue-like RPG combined with minsweeper. You are a treasure seeker who sneak into a 8 storey dungeon overwhelmed with dangerous monsters to steal the ultimate treasure at the top floor. You have the amazing "minesweeper" ability to sense the presence of surroundings'  ememies. Use this power wisely to avoid encountering monsters as much as possible such that you won't run out of stamina before getting the ultimate treasure. There are also mysterious merchants and useful treasures scattered across the dungeon to help you survive  till the end.

Player start on 1st floor with 30 health. Everytime you enter a new floor, every tile except your starting location will be "?". Unlike traditional minsweeper game where you can click any tile you wish, treasure seeker doesn't have the ability of teleport. You can only reveal and move to the 4 tiles next your current position by pressing up, down, left and right key. Whenever you reveal a "?" tile, there are three basic possible outcome:  

1)empty tile: nothing will happen  
2)monster tile: The monster on that tile will ambush you, result in losing hp 
3)items tile: an items (e.g. gem, potion, treasure chest) will appear on the tile, press the same key again to obtain it  

After a tile become an empty tile, a number ranged from 0 to 8 will appear on the tile to indicate the number of surroundings' enemies. Player can only move to a number tile.  

## Features
### Player attribute
int max_hp; //maximum hp you can have  
int hp; //gameover when health reduced to 0  
int x, y; //position of player in the dungeon  
int score; //get as much score as possible
### Encounters
'E' //Monster, lose hp when encounter  
'p' //lesser healing potion, heal for a small percentage of _hp  
'P' //greater healing potion, heal for a larger percentage of hp  
'g' //lesser health gem, increase max_hp by 5  
'G' //greater health gem, increase max_hp by 10  
't' //mini treasure chest, gain a small amount of score  
'T' //treasure chest, gain a large amount of score  
'U' //stair up to the next floor, randomly generated one per each floor  

### Teasures (forget about this)
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
### Doom mode
Unlock after the first time finish the normal mode. In this mode, every floor will have a random negative event which make it harder for player to survive. 2 random events on 4th and 8th floor. Examples of negative event:  
1) 10 extra monsters on the floor  
2) tiles larger than '2' become '2'  
3) die instantly when you encounter the third monster  
4) when calculate damage taken, roll an extra 10 faces die  
5) tiles smaller than '1' become '1'  
6) after the 30th move, take 2 damages every move  
7) lose gold instead of gain gold when picking gold pile, double the number of gold piles on this floor
8) cannot move to the next floor until there are less than 10 '?' tiles on this floor  
### Score system
Player will gain or lose score when they achieve certain progress in the game. It means to let player challenge themselves for getting the highest score possible.  
1) reveal a tile: +1  
2) encounter monster: -10  
3) get 't': +10
4) get 'T': +25
4) pass a floor: +100  
5) get the ultimate treasure: +1000  
6) each hp remained: +5  

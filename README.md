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

| Feature             | Requirement | Description                                                                                                                                                    |
|---------------------|:-----------:|----------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Level generation    |      1      | Enemies, power-ups and other objects will be place randomly when generating a new level.                                                                       |
| Combat event        |      1      | Combat damage will include a random element.                                                                                                                   |
| Game objects        |     2, 3    | Enemies, power-ups, .etc will be stored as instance objects of the corresponding class, create or removed when necessary.<br>(e.g Delete when enemy is killed) |
| Save game           |      4      | Game can be saved in at any time. It is saved using files.                                                                                                     |
| Modular programming |      5      | Each module will be contained in a separate file.                                                                                                              |



## Features

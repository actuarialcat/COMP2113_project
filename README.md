# COMP2113_project
COMP 2113 Project for Group 225

## Brief identification of the team members

Fong Cheuk Ting, u3035688784  
[Your name], [Your UID]

## Game description with basic game rules

The game we decided to develop is "魔塔". It is fixed-values RPG with fixed battle result, fixed enemy and fixed rescources such that every same decision will always results in same outcome. However, An extra new gamemode willbe develped with random elements to make the gamemode more "roguelike".

In the game, you will control the champion who attempts to challenge a magical tower. Your goal is to climb to the top to defeat the final boss in order to save the world. The tower is full of dangerous monsters that block your way to the top. You have to battle against them and they will deal damage to you. If your health drop to zero, you will die. Luckily, the tower is also full of strategic resources to help you getting stronger and win the game.

## Features and functions
### Champion attribute
int level; //increases stats when level up  
int hp; //gameover when health reduced to 0  
int atk; //attack  
int def; //defence  
int mdef; //magical defence  
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
#### health potions
#### keys
#### special items
### Display
### rougelike mode

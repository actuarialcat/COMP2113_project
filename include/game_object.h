//Header file for game object classes

#ifndef GAME_OBJECT_H_
#define GAME_OBJECT_H_

class PlayerClass{
public:
    int level;

private:
    void move(int x, int y);    //move the player
};

//****************************** 

class MapClass{
public:
    
private:

};

//****************************** 

class Wall{
public:
    char display_char;

    //TODO:
    bool collision_check(); 
    void interaction();

private:

};

#endif  // GAME_OBJECT_H_

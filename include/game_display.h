#ifndef GAME_DISPLAY_H
#define GAME_DISPLAY_H

void InitGameDisplay(WINDOW *&stats, WINDOW *&dungeon, WINDOW *&datalog, int height, int width);
void update_all_display(Character p, Map m, string message, WINDOW *stats, WINDOW *dungeon, WINDOW *datalog);

#endif
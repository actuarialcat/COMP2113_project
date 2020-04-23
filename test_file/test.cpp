//adhoc testing, please ignore

#include <iostream>

#include "../include/game_object.h"

using namespace std;

int main() {

    GameObjectBase *w = new ObjectWall('W');
    GameObjectBase *p = new ObjectEnemy('E', 10);

    Character x('@');

    cout << w->getDisplayChar() << endl;
    cout << p->getDisplayChar() << endl;

    w->postMoveAction(x);
    p->postMoveAction(x);

    

    return 0;
}




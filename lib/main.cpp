#include <iostream>
using namespace std;
#include "../include/menu.h"

using namespace std;
int main(){
  //Initialize menu
  MainMenuInit();   //manu.h

  //clear screen
  for (int i=0;i<50;i++){
    cout << endl;
  }
  //prgram end
  cout << "Program end" << endl;
  return (0);
}

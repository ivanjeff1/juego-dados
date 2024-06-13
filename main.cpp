#include <iostream>
#include <stdlib.h>
#include "rlutil.h"
#include <ctime>

#include "funciones.h"

using namespace std;

int tirarDado(int posx, int posy){
    int dado =rand()%6 + 1;

    for(int i=0; i<20; i++){
        dibujarDados(rand()%6 + 1, posx, posy);
        rlutil::msleep(5);
    }
    dibujarDados(dado, posx, posy);

    return dado;

 }

int main()
{
  srand(time(0));
    rlutil::hidecursor();
  rlutil::saveDefaultColor();


  for( int i=1; i<=6; i++){
      tirarDado(i*10, rand()%10 +1);

  }


    rlutil::anykey();
    rlutil::resetColor();
   return 0;


}



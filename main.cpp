#include <iostream>
#include <stdlib.h>
#include "rlutil.h"
#include <ctime>

#include "funciones.h"

using namespace std;

///void tirarDado(int posx, int posy)

int tirarDado(int posx, int posy){
    int dado =rand()%6 + 1; ///semilla dado aleatorio

    for(int i=0; i<20; i++){  ///for que tira los dadfos
        dibujarDados(rand()%6 + 1, posx, posy);
        rlutil::msleep(5);
    }
    dibujarDados(dado, posx, posy);


    return dado;    ///retorna el dado que se tiro

}

int main()
{
  /// menu();



   srand(time(0));
    rlutil::hidecursor();
  rlutil::saveDefaultColor();


  for( int i=1; i<=6; i++){
      tirarDado(i*10, rand()%10 +1);///devuelve el dado que tira

  }


    rlutil::anykey();
    rlutil::resetColor();


   return 0;


}



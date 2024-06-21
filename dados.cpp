#include <iostream>
#include "rlutil.h"
#include "dados.h"

using namespace std;

void dibujarDado(int numero, int posx, int posy){
    dibujarCuadrado(posx, posy);
    dibujarSombra(posx, posy);
    dibujarPuntos(numero, posx, posy);
}


//Efecto
int efectoDado (){
int posy[6]{rand()%6+1,rand()%6+1,rand()%6+1,rand()%6+1,rand()%6+1,rand()%6+1};
    bool seleccionados[6]{};
    int dados[6]; //guardo el valor

    rlutil::hidecursor();
    rlutil::saveDefaultColor();

    for(int i=1; i<=6; i++){
        dibujarCuadrado(i*10, posy[i-1]);
        dibujarSombra(i*10, posy[i-1]);
    }

    for(int i = 1; i <= 6; i++) {
        int posx = rand()%6;

       while(seleccionados[posx]){
        posx = rand()%6;
       }
       seleccionados[posx] = true;

     dados[posx] = tirarDado((posx+1)*10, posy[posx]);//guarda valor de dado



    }

    rlutil::anykey();
    rlutil::resetColor();
    return analizarValor(dados);

}

//Analizar valor
 int analizarValor(int dados[6]) {
    int excepcionReseteo = 0;   // Contador
    int excepcionEscalera = 0;  // Contador
    int excepcionSextetoX = 0; //
    int conteo[6] = {0};        // contea cada uno de los valores dados por el el dado 1-6

    // Contar los dados con valor 6 para el reseteo
    for (int i = 0; i < 6; i++) {
        if (dados[i] == 6) {
            excepcionReseteo++;
        }
        if (dados[i] >= 1 && dados[i] <= 6) {
            conteo[dados[i] - 1]++;
        }
    }

     // Verificar si hay un sexteto con numero x
      for (int i = 0; i < 6; i++) {
        if (conteo[i] == 6) {
            excepcionSextetoX = i + 1;  // Guarda el numero x que forma el sexteto
            break;
        }
    }



    // Verificar si hay una escalera
    bool esEscalera = true;
    for (int i = 0; i < 6; i++) {
        if (conteo[i] != 1) {
            esEscalera = false;
            break;
        }
    }


    if (excepcionSextetoX != 0 && excepcionSextetoX != 6) {
        return excepcionSextetoX;  // devuelve el numero
    }


    if (excepcionReseteo == 6) {
        return 6; // Reseteo
    }
    if (esEscalera) {
        return 21; // Escalera
    }



    int sumaPuntos = 0;
    for (int i = 0; i < 6; i++) {
        sumaPuntos += dados[i];
    }
    return sumaPuntos;
}



//Tirar


int tirarDado(int posx, int posy){
    int dado = rand()%6 + 1;

    for(int i=0; i<15; i++){
    dibujarDado(rand()%6+1, posx,posy);
    rlutil::msleep(10);

    }
     dibujarDado(dado, posx,posy);

    return dado;
}


// Puntos
void dibujarPuntos(int numero, int posx, int posy){
    rlutil::setColor(rlutil::BLACK);
    rlutil::setBackgroundColor(rlutil::RED);

    switch(numero) {
        case 1:
            rlutil::locate(posx+3, posy+1);
            cout << (char)254;
            break;
        case 2:
            if(rand()%2){
            rlutil::locate(posx+1, posy);
            cout << (char)220;
            rlutil::locate(posx+5, posy+2);
            cout << (char)223;
            }
            else {
            rlutil::locate(posx+1, posy+2);
            cout << (char)223;
            rlutil::locate(posx+5, posy);
            cout << (char)220;
            }
            break;
        case 3:
            rlutil::locate(posx+3, posy+1);
            cout << (char)254;
             if(rand()%2){
            rlutil::locate(posx+1, posy);
            cout << (char)220;

            rlutil::locate(posx+5, posy+2);
            cout << (char)223;
            }
            else {
            rlutil::locate(posx+1, posy+2);
            cout << (char)223;
            rlutil::locate(posx+5, posy);
            cout << (char)220;
            }
            break;
        case 4:
            rlutil::locate(posx+1, posy);
            cout << (char)220;
            rlutil::locate(posx+5, posy);
            cout << (char)220;
            rlutil::locate(posx+1, posy+2);
            cout << (char)223;
            rlutil::locate(posx+5, posy+2);
            cout << (char)223;
            break;
        case 5:
            rlutil::locate(posx+1, posy);
            cout << (char)220;
            rlutil::locate(posx+5, posy);
            cout << (char)220;
            rlutil::locate(posx+3, posy+1);
            cout << (char)254;
            rlutil::locate(posx+1, posy+2);
            cout << (char)223;
            rlutil::locate(posx+5, posy+2);
            cout << (char)223;
            break;
        case 6:
            rlutil::locate(posx+1, posy);
            cout << (char)220;
            rlutil::locate(posx+5, posy);
            cout << (char)220;
            rlutil::locate(posx+1, posy+2);
            cout << (char)223;
            rlutil::locate(posx+5, posy+2);
            cout << (char)223;

            if(rand()%2){

            rlutil::locate(posx+3, posy);
            cout << (char)220;
             rlutil::locate(posx+3, posy+2);
            cout << (char)223;
            }
            else{
                rlutil::locate(posx+1, posy+1);
            cout << (char)254;
             rlutil::locate(posx+5, posy+1);
            cout << (char)254;
            }

            break;
    }
}

void dibujarSombra(int posx, int posy){
    rlutil::setColor(rlutil::GREY);
    rlutil::setBackgroundColor(rlutil::BLACK);

    for(int y = posy; y <= posy + 2; y++) {
        rlutil::locate(posx + 7, y);
        if(y == posy) {
            cout << (char)220;
        } else {
            cout << (char)219;
        }
    }

    for(int x = posx + 1; x <= posx + 7; x++) {
        rlutil::locate(x, posy + 3);
        cout << (char)223;
    }
}

void dibujarCuadrado(int posx, int posy){
    rlutil::setColor(rlutil::RED);

    for(int x = posx; x <= posx + 6; x++) { // dibuja un cuadrado
        for(int y = posy; y <= posy + 2; y++) {
            rlutil::locate(x, y);
            cout << (char)219;
        }
    }
}




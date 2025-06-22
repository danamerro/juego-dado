#include <iostream>
#include <cstdlib>
#include <ctime>
#include "juego/juego.h"


using namespace std;

int main() {
    srand(time(0));
    int mejorPuntuacion = 0;
    string mejorJugador = "NULL";
    juego(mejorPuntuacion, mejorJugador);
    return 0;
}


#include "estadisticas.h"
#include <iostream>
#include <string>

using namespace std;

void modificarEstadistica(int puntaje, string posicion, int &mejorPuntuacion, string &mejorJugador);

void modificarEstadistica(int puntaje, string posicion, int &mejorPuntuacion, string &mejorJugador) {
    if (puntaje > mejorPuntuacion) {
        mejorPuntuacion = puntaje;
        mejorJugador = posicion;
    }
}
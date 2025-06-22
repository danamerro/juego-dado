#include <string>

using namespace std;

void titulo();
void instruccionesIniciales();
void ingresarNombresJugadores(string &nombreJ1, string &nombreJ2);
void mostrarPantallaEstado(int puntaje[2],int cantDadosD6[2], int ronda, string jugador, string posicion[2]);
void mostrarPantallaTirosDadosD12(int dadosD12[2]);
void mostrarMejorPuntaje(int mejorPuntuacion, string mejorJugador);
void limpiarPantalla();
void creditosDesarrolladores();

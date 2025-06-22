#include <string>

using namespace std;

void tiradaInicial(int numIniJ1, int numIniJ2,string posicion[2],string nombreJ1, string nombreJ2);
void tiradaD6(int dadosStock[11],int cantDadosD6);
void imprimirDadoD6(int valor);
void calcularPuntajeYDados(int sumaSeleccionada, int dadosD12[2], int &puntaje, int cantDadosJugados,int &cantDadosD6Oponente, int &cantDadosD6Jugador,string posicion);
void seleccionDado(int cantDadosD6,int dadosStock[11],int &sumaSeleccionada,int &cantDadosJugados,int dadosD12[2]);

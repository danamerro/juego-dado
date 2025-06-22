#include "pantallasYNombresJugadores.h"
#include <iostream>
#include <limits>

using namespace std;

void titulo();
void instruccionesIniciales();
void ingresarNombresJugadores(string &nombreJ1, string &nombreJ2);
void mostrarPantallaEstado(int puntaje[2],int cantDadosD6[2], int ronda, string jugador, string posicion[2]);
void mostrarPantallaTirosDadosD12(int dadosD12[2]);
void mostrarMejorPuntaje(int mejorPuntuacion, string mejorJugador);
void limpiarPantalla();
void creditosDesarrolladores();

void ingresarNombresJugadores(string &nombreJ1, string &nombreJ2) {
  cout << "Ingrese el nombre del primer jugador: " <<endl;
  cin >> nombreJ1;
  cout << "Ingrese el nombre del segundo jugador: " <<endl;
  cin >> nombreJ2;
  cin.ignore(numeric_limits<streamsize>::max(), '\n'); //esto ignora el buffer para no tener problemas con el limpiar pantalla
}

void titulo() {
    cout << R"(

  ______        __                    _           _
 |  ____|      / _|                  | |         | |
 | |__   _ __ | |_ _ __ ___ _ __   __| | __ _  __| | ___  ___
 |  __| | '_ \|  _| '__/ _ \ '_ \ / _` |/ _` |/ _` |/ _ \/ __|
 | |____| | | | | | | |  __/ | | | (_| | (_| | (_| | (_) \__ \
 |______|_| |_|_| |_|  \___|_| |_|\__,_|\__,_|\__,_|\___/|___/

 +------------------------------+
 |                              |
 |  1 - Nuevo juego             |
 |  2 - Estadisticas            |
 |  3 - Creditos                |
 |  4 - Salir                   |
 |                              |
 +------------------------------+

)";
}

void instruccionesIniciales() {
    cout << R"(
================================================================================
                              BIENVENIDOS A
   ______        __                    _           _
  |  ____|      / _|                  | |         | |
  | |__   _ __ | |_ _ __ ___ _ __   __| | __ _  __| | ___  ___
  |  __| | '_ \|  _| '__/ _ \ '_ \ / _` |/ _` |/ _` |/ _ \/ __|
  | |____| | | | | | | |  __/ | | | (_| | (_| | (_| | (_) \__ \
  |______|_| |_|_| |_|  \___|_| |_|\__,_|\__,_|\__,_|\___/|___/

================================================================================

Instrucciones del juego:

Enfrentados es un juego de dados para dos jugadores, donde intervienen el azar
y las matematicas. El objetivo es sumar la mayor cantidad de puntos en un total
de TRES rondas.

* Cada jugador comienza con:
  - 6 dados de seis caras (dados stock)
  - 2 dados de doce caras (compartidos por ronda)

* Al comenzar el juego:
  - Cada jugador lanza un dado.
  - Quien saque el numero mayor empieza la partida.
  - En caso de empate, se repite hasta desempatar.

* Al iniciar su turno:
  1. El jugador lanza los 2 dados de 12 caras → suma = numero objetivo (entre 2 y 24).
  2. Luego lanza todos sus dados stock.
  3. Debe seleccionar los dados que sumen exactamente el numero objetivo.

* Si lo logra (tirada exitosa):
  - Gana puntos: (suma seleccionada) x (cantidad de dados elegidos).
  - Pierde esos dados elegidos, que pasan al oponente.
  - Si se queda sin dados, gana automaticamente con 10.000 puntos extra.

* Si NO lo logra:
  - El oponente le da un dado (solo si tiene mas de 1).
  - Si el oponente tiene solo un dado, no hay penalizacion.

* Luego juega el otro jugador con sus dados correspondientes.

* El juego termina cuando:
  - Se juegan las 3 rondas.
  - O un jugador se queda sin dados (gana automaticamente).

Prepara tus dados, tus neuronas y que empiece la batalla!

================================================================================
)" << endl;
}

void mostrarPantallaEstado(int puntaje[2],int cantDadosD6[2], int ronda, string jugador, string posicion[2]) {
  //Esta pantalla reutilizable permite ver el turno y datos de los jugadores
  cout << "+--------------------------------------------------------------+" << endl;
  cout << " Turno de [" << jugador << "]" << endl;
  cout << " Cant de dados 6 lados: [" << cantDadosD6[0] << "] de [" << posicion[0] << "]" << endl;
  cout << " Cant de dados 6 lados: [" << cantDadosD6[1] << "] de [" << posicion[1] << "]" << endl;
  cout << "" << endl;
  cout << " Ronda [" << ronda << "]" << endl;
  cout << " Puntos [" << posicion[0] << "]: [" << puntaje[0] << "]" << endl;
  cout << " Puntos [" << posicion[1] << "]: [" << puntaje[1] << "]" << endl;
  cout << "" << endl;
  cout << "+--------------------------------------------------------------+" << endl;
}

void mostrarPantallaTirosDadosD12(int dadosD12[2]) {
  //Esta otra pantalla permite ver los dados D12 que se tiraron del jugador
  cout << "" << endl;
  cout << "                        Dado D12      Dado D12                " << endl;
  cout << "                          [" << dadosD12[0] << "]            [" << dadosD12[1] << "]            " << endl;
  cout << "" << endl;
  cout << "                        La suma objetivo es: " << (dadosD12[0] + dadosD12[1]) <<"             "<<endl;
  cout << "+--------------------------------------------------------------+" << endl;
}

void mostrarMejorPuntaje(int mejorPuntuacion, string mejorJugador) {
  cout << "+--------------------------------------------------------------+" << endl;
  cout << " Mejor puntuacion actual                                      " << endl;
  cout << "                                                              " << endl;
  cout << " Jugador: [" << mejorJugador << "]" << endl;
  cout << " Puntos : [" << mejorPuntuacion << "]" << endl;
  cout << "                                                              " << endl;
  cout << "+--------------------------------------------------------------+" << endl;
}

void limpiarPantalla() {
  //Esta funcion tiene una pausa hasta que se presione una tecla, luego hace un for que imprime 100 saltos de linea
  cout << "Presiona Enter para continuar..." << endl;
  cin.get();
  for (int i = 0; i < 100; ++i) {
    std::cout << std::endl;
  }
}

void creditosDesarrolladores() {
  cout << "+--------------------------------------------------------------+" << endl;
  cout << " Desarrollares de Enfrendados                                   " << endl;
  cout << "                                                                " << endl;
  cout << " Equipo 69:                                                     " << endl;
  cout << " Dana Milena Erro                         Legajo: 32526         " << endl;
  cout << " Mauro Gaston Rostirolla                  Legajo: 32436         " << endl;
  cout << "                                                                " << endl;
  cout << "+--------------------------------------------------------------+" << endl;
}









#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


void juego();
void titulo();
void instruccionesIniciales();
void ingresarNombresJugadores(string &nombreJ1, string &nombreJ2);
void tiradaInicial(int numIniJ1, int numIniJ2,string posicion[2],string nombreJ1, string nombreJ2);
void tirarD12(int dadosD12[2]);




int main() {
    srand(time(0));
    juego();
    return 0;
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
 |  3 - Salir                   |
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


void juego() {
    string nombreJ1;
    string nombreJ2;
    int numIniJ1;
    int numIniJ2;
    string posicion[2];
    int dadosD12[2];


    int opcion;

    do{
        titulo();
        cin >> opcion;

        switch (opcion){
            case 1:
                instruccionesIniciales();
                ingresarNombresJugadores(nombreJ1,nombreJ2);
                tiradaInicial(numIniJ1,numIniJ2,posicion,nombreJ1,nombreJ2);
                tirarD12(dadosD12);
            break;
            case 2:
                cout << endl;
            cout << "Ud eligio Estadisticas" << endl;
            break;
            case 3:
                cout << endl;
            cout << "Ud eligio Creditos" << endl;
            break;
            case 0:
                cout << endl;
            cout << "Fin del juego" << endl;
            break;
            default:
                cout << endl;
            cout << "Opcion no valida..." << endl;

        }
        system("pause");
    } while (opcion != 0);

}

void ingresarNombresJugadores(string &nombreJ1, string &nombreJ2) {
    cout << "Ingrese el nombre del primer jugador: " <<endl;
    cin >> nombreJ1;
    cout << "Ingrese el nombre del segundo jugador: " <<endl;
    cin >> nombreJ2;
}

void tiradaInicial(int numIniJ1, int numIniJ2,string posicion[2],string nombreJ1, string nombreJ2) {
    do {
        numIniJ1 = rand()%6+1;
        numIniJ2 = rand()%6+1;
    }while (numIniJ1 == numIniJ2);
    if (numIniJ1 > numIniJ2) {
        posicion[0] = nombreJ1;
        posicion[1] = nombreJ2;
    }else {
        posicion[0] = nombreJ2;
        posicion[1] = nombreJ1;
    }
    cout << nombreJ1 <<" obtuvo: "<< numIniJ1 << endl;
    cout << nombreJ2 <<" obtuvo: "<< numIniJ2 << endl;
    cout << posicion[0] << " arranca el juego " << endl;
}

/** TODO: ACA VA A IR EL TABLERO CON LOS PUNTAJES Y DEMÁS*/

void  tirarD12(int dadosD12[2]) {
    dadosD12[0] = rand()%12+1;
    dadosD12[1] = rand()%12+1;
    cout << "te salio el dado: "<< dadosD12[0] <<endl;
    cout << "y el dado: "<< dadosD12[1] <<endl;
}
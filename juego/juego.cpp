#include "juego.h"
#include "../funcionesD6/funcionesD6.h"
#include "../funcionesD12/funcionesD12.h"
#include "../pantalla/pantallasYNombresJugadores.h"
#include "../estadisticas/estadisticas.h"
#include <iostream>
#include <string>
#include <limits>

using namespace std;

void juego(int &mejorPuntuacion, string &mejorJugador);
void confirmarGanador(int puntaje[2], string posicion[2], int &mejorPuntuacion, string &mejorJugador);

void juego(int &mejorPuntuacion, string &mejorJugador) {
    string nombreJ1;
    string nombreJ2;
    int numIniJ1;
    int numIniJ2;
    string posicion[2];
    int dadosD12[2];
    int dadosStock[11];
    int puntaje[2];

    int opcion;

    do{
        titulo();
        cin >> opcion;
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); //esto ignora el buffer para no tener problemas con el limpiar pantalla
        //Es un switch para cada opcion del juego. Las llaves {} en el case 1 son para poder inicializar variables dentro
        switch (opcion){
            case 1: {
                puntaje[0] = 0;
                puntaje[1] = 0;
                int cantDadosD6[2] = {6,6};
                int sumaSeleccionada = 0;
                int cantDadosJugados = 0;
                int ronda = 1;
                int oponente;

                instruccionesIniciales();
                ingresarNombresJugadores(nombreJ1,nombreJ2);
                tiradaInicial(numIniJ1,numIniJ2,posicion,nombreJ1,nombreJ2);
                limpiarPantalla();

                //este do while lo que hace es que, mientras la condicion de que la ronda sea menor o igual a 3, va a realizar todas las acciones
                //en caso de que un jugador se quede sin dados se corta directamente
                do {
                    //Aca se utiliza un for ya que todas las llamadas a las funciones se repiten, solo varia los datos de el jugador 1 o 2
                    for (int i = 0; i <= 1; i++) {
                        //ambas variables dentro de mostrarPantallaEstado tienen el mismo nombre, solo que posicion[i] hace referencia a el jugador actual, y el otro a ambos.
                        //no utilizo la variable oponente (creada mas adelante) ya que posicion juega con las posiciones junto con cantDadosD6
                        //si utilizara la variable oponente, se mezclaria las cantidades de dados de los jugadores
                        mostrarPantallaEstado(puntaje,cantDadosD6, ronda, posicion[i], posicion);
                        tirarD12(dadosD12);
                        limpiarPantalla();

                        mostrarPantallaEstado(puntaje,cantDadosD6, ronda, posicion[i], posicion);
                        mostrarPantallaTirosDadosD12(dadosD12);
                        tiradaD6(dadosStock,cantDadosD6[i]);

                        cout << "Ahora " << posicion[i] << " te toca seleccionar los dados que, sumados, coincidan con la SUMA OBJETIVO" << endl;
                        cout << "Ingresa 0 si la suma de los dados no llega a la SUMA OBJETIVO" << endl;

                        seleccionDado(cantDadosD6[i],dadosStock,sumaSeleccionada,cantDadosJugados,dadosD12);

                        //Este if es para solucionar la funcion calcularPuntajeYDados, como se tiene que enviar tanto la cantidad de
                        //dados stock del jugador y del oponente, el for no puede solucionar eso. Este auxiliar
                        //permite que se pueda, en base a la posicion de i, seleccionar el jugador opuesto
                        oponente = 0;
                        if (i == 0) {
                            oponente = 1;
                        }

                        calcularPuntajeYDados(sumaSeleccionada, dadosD12, puntaje[i], cantDadosJugados,cantDadosD6[oponente], cantDadosD6[i],posicion[i]);

                        //verifica si alguno de los jugadores obtuvo el puntaje ganador al quedar sin dados
                        //de ser asi setea la ronda en 4 para cortar el do while y hace un break para cortar el for
                        if (puntaje[i] >= 10000) {
                            ronda = 4;
                            break;
                        }
                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //esto ignora el buffer para no tener problemas con el limpiar pantalla
                    }

                    ronda++;
                }while (ronda <=3);

                confirmarGanador(puntaje, posicion, mejorPuntuacion, mejorJugador);

                break;
            }
            case 2:
                cout << endl;
                mostrarMejorPuntaje(mejorPuntuacion, mejorJugador);
                limpiarPantalla();
                break;
            case 3:
                cout << endl;
                creditosDesarrolladores();
                limpiarPantalla();
                break;
            case 4: {
              	int salir;
                cout << endl;
                cout << "Esta seguro que desea abandonar el juego?" << endl;
                cout << "1 - Si" << endl;
                cout << "2 - No" << endl;
                do {
					cin >> salir;
            		if (cin.fail() || (salir != 1 && salir != 2)) {
              			cout << "Ingrese 1 o 2" << endl;
              			cin.clear();
        				cin.ignore(numeric_limits<streamsize>::max(), '\n'); //esto ignora el buffer para no tener problemas con el limpiar pantalla
            		} else {
               			break;
            		}
       		 	} while (true);


                if (salir != 1) {
                  opcion = 5;
                } else {
                  cout << "Fin del juego" << endl;
                }
                break;
                }
            case 5:
              	cout << endl;
                break;
            default:
                cout << endl;
                cout << "Opcion no valida..." << endl;
        }
    } while (opcion != 4);

}

void confirmarGanador(int puntaje[2], string posicion[2], int &mejorPuntuacion, string &mejorJugador) {
    if (puntaje[0] > puntaje[1]) {
        cout << "Ganaste " << posicion[0] << " con " << puntaje[0] << " puntos." << endl;
        modificarEstadistica(puntaje[0], posicion[0],mejorPuntuacion, mejorJugador);
        limpiarPantalla();
    } else if (puntaje[0] < puntaje[1]) {
        cout << "Ganaste " << posicion[1] << " con " << puntaje[1] << " puntos." << endl;
        modificarEstadistica(puntaje[1], posicion[1],mejorPuntuacion, mejorJugador);
        limpiarPantalla();
    } else {
        cout << "Empataron, todo mal :(" << endl;
        limpiarPantalla();
    }
}
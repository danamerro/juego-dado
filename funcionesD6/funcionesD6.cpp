#include "funcionesD6.h"
#include <iostream>
#include <string>
#include <limits>

using namespace std;

void tiradaInicial(int numIniJ1, int numIniJ2,string posicion[2],string nombreJ1, string nombreJ2);
void tiradaD6(int dadosStock[11],int cantDadosD6);
void imprimirDadoD6(int valor);
void calcularPuntajeYDados(int sumaSeleccionada, int dadosD12[2], int &puntaje, int cantDadosJugados,int &cantDadosD6Oponente, int &cantDadosD6Jugador,string posicion);
void seleccionDado(int cantDadosD6,int dadosStock[11],int &sumaSeleccionada,int &cantDadosJugados,int dadosD12[2]);





void tiradaInicial(int numIniJ1, int numIniJ2,string posicion[2],string nombreJ1, string nombreJ2) {
    //Se hace un bucle donde se tira los dados para ambos jugadores, si el numero es igual se vuelve a realizar la accion
    //hasta que ambos numeros sean distintos
    do {
        numIniJ1 = rand()%6+1;
        numIniJ2 = rand()%6+1;
    }while (numIniJ1 == numIniJ2);

    //En base a la tirada se elije la posicion del jugador en el vector
    if (numIniJ1 > numIniJ2) {
        posicion[0] = nombreJ1;
        posicion[1] = nombreJ2;
    }else {
        posicion[0] = nombreJ2;
        posicion[1] = nombreJ1;
    }

    cout << nombreJ1 <<" obtuvo: "<< numIniJ1 << endl;
    imprimirDadoD6(numIniJ1);
    cout << endl;
    cout << nombreJ2 <<" obtuvo: "<< numIniJ2 << endl;
    imprimirDadoD6(numIniJ2);
    cout << endl;
    cout << posicion[0] << " arranca el juego " << endl;
}

void tiradaD6(int dadosStock[11],int cantDadosD6) {
    //Se tiran los dados de 6 caras y se muestra por pantalla cuales son
    int i;
    for (i=0;i<cantDadosD6;i++) {
        dadosStock[i]= rand()%6+1;
    }
    for (i = 0; i < cantDadosD6; i++) {
        cout << "Dado " << (i + 1) << ":" << endl;
        imprimirDadoD6(dadosStock[i]);
        cout << "    " << dadosStock[i] << endl;
        cout << endl;
    }
    cout << "+--------------------------------------------------------------+" << endl;
}

void imprimirDadoD6(int valor) {
    const string caras[6] = {
        // Dado 1
        "+-------+\n"
        "|       |\n"
        "|   o   |\n"
        "|       |\n"
        "+-------+",

        // Dado 2
        "+-------+\n"
        "| o     |\n"
        "|       |\n"
        "|     o |\n"
        "+-------+",

        // Dado 3
        "+-------+\n"
        "| o     |\n"
        "|   o   |\n"
        "|     o |\n"
        "+-------+",

        // Dado 4
        "+-------+\n"
        "| o   o |\n"
        "|       |\n"
        "| o   o |\n"
        "+-------+",

        // Dado 5
        "+-------+\n"
        "| o   o |\n"
        "|   o   |\n"
        "| o   o |\n"
        "+-------+",

        // Dado 6
        "+-------+\n"
        "| o   o |\n"
        "| o   o |\n"
        "| o   o |\n"
        "+-------+"
    };

    cout << caras[valor - 1] << endl;
}

void calcularPuntajeYDados(int sumaSeleccionada, int dadosD12[2], int &puntaje, int cantDadosJugados,int &cantDadosD6Oponente, int &cantDadosD6Jugador,string posicion) {
    if (sumaSeleccionada == (dadosD12[0] + dadosD12[1])) {
        puntaje += (sumaSeleccionada * cantDadosJugados);
        if (cantDadosJugados == cantDadosD6Jugador) {
            cout << "sumaste 10.000 puntos: " << endl;
            puntaje += 10000;
        }else {
            cantDadosD6Jugador -= cantDadosJugados;
            cantDadosD6Oponente += cantDadosJugados;
            cout << "Te quedan   " << cantDadosD6Jugador << " dados." << endl;
        }
    }else {
        cout << "No llega a la suma seleccionada."<< endl;
        if (cantDadosD6Oponente > 1) {
            cantDadosD6Oponente--;
            cantDadosD6Jugador++;
            cout << "el oponente te dio un dado."<< endl;
        }else {
            cout << "no te dan dado, el oponente solo le queda 1."<< endl;
        }
        cout << "Te quedan   " << cantDadosD6Jugador << " dados." << endl;
    }
}

void seleccionDado(int cantDadosD6,int dadosStock[11],int &sumaSeleccionada,int &cantDadosJugados,int dadosD12[2]) {
    int dadosDisponibles[11];
    int seleccion = 0;
    //llamo a sumaSeleccionada y a cantDadosJugados, luego los igualo a 0 porque si no hago eso el resultado de ambas variables se acumulan con el del anterior
    //jugador.
    sumaSeleccionada = 0;
    cantDadosJugados = 0;

    //se realizan dos bucles, el primero llena todo el vector de 1, el segundo solo cambia a 0 los dados que tenga en stock el jugador
    //esto sirve para verificar el numero que se eligio esta disponible o no, esto se basa en la posicion
    int i;
    for (i = 0; i < 11; i++) {
        dadosDisponibles[i]=1;
    }
    for (i = 0; i < cantDadosD6; i++) {
        dadosDisponibles[i]=0;
    }

    do {
        cout << "Ingresa el numero indicado en \"Dado x\" siendo X el digito que debe ingresar: " << endl;
        //aca el jugador elije la posicion realmente, verifica si esa posicion tiene un 0 o 1 y en base a eso realiza la suma
        do {
			cin >> seleccion;
            if (cin.fail()) {
              	cout << "Ingrese un numero indicado en \"Dado x\" siendo X el digito que debe ingresar, cualquier otra opcion no se tomara" << endl;
              	cin.clear();
        		cin.ignore(numeric_limits<streamsize>::max(), '\n'); //esto ignora el buffer para no tener problemas con el limpiar pantalla
            } else {
               	break;
            }
        } while (true);

        if (seleccion >= 1 && seleccion <= cantDadosD6) {
            if (dadosDisponibles[seleccion-1]==0) {
                dadosDisponibles[seleccion - 1] = 1;
                cantDadosJugados++;
                sumaSeleccionada += dadosStock[seleccion - 1];

                //Esta condicion es para verificar si la suma llega a la suma objetivo y, en caso afirmativo, termina la seleccion
                if (sumaSeleccionada == (dadosD12[0] + dadosD12[1])) {
                    cout << "Llegaste a la suma objetivo" << endl;
                    seleccion = 0;
                }
            }else {
                cout << "Dado ya elegido, seleccione otro: " << endl;
            }
        }else {
            //esta condicion es para verificar si el nro que el jugador eligio pasa del rango de dados en stock y no es 0
            if (seleccion != 0) {
                cout << "El numero esta fuera de rango." << endl;
            }
        }

    }while (seleccion != 0 && cantDadosJugados != cantDadosD6);
}
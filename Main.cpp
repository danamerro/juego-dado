#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;


void juego();
void titulo();
void instruccionesIniciales();
void ingresarNombresJugadores(string &nombreJ1, string &nombreJ2);
void tiradaInicial(int numIniJ1, int numIniJ2,string posicion[2],string nombreJ1, string nombreJ2);
void tirarD12(int dadosD12[2]);
void tiradaD6(int dadosStock[11],int cantDadosD6);
void seleccionDado(int cantDadosD6,int dadosStock[11],int &sumaSeleccionada,int &cantDadosJugados,int dadosD12[2]);
void mostrarPantallaEstado(int puntaje[2],int cantDadosD6[2], int ronda, string jugador, string posicion[2]);
void limpiarPantalla();
void mostrarPantallaTirosDadosD12(int dadosD12[2]);
void calcularPuntajeYDados(int sumaSeleccionada, int dadosD12[2], int &puntaje, int cantDadosJugados,int &cantDadosD6Oponente, int &cantDadosD6Jugador,string posicion);
void imprimirDadoD6(int valor);
void imprimirDadoD12(int valor);
void modificarEstadistica(int puntaje, string posicion, int &mejorPuntuacion, string &mejorJugador);
void mostrarMejorPuntaje(int mejorPuntuacion, string mejorJugador);
void confirmarGanador(int puntaje[2], string posicion[2], int mejorPuntuacion, string mejorJugador);


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


void juego() {
    string nombreJ1;
    string nombreJ2;
    int numIniJ1;
    int numIniJ2;
    string posicion[2];
    int dadosD12[2];
    int dadosStock[11];
    int puntaje[2];
    int mejorPuntuacion = 0;
    string mejorJugador = "NULL";

    int opcion;

    do{
        titulo();
        cin >> opcion;

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
                cout << "Ud eligio Creditos" << endl;
                break;
            case 4:
                cout << endl;
                cout << "Fin del juego" << endl;
                break;
            default:
                cout << endl;
                cout << "Opcion no valida..." << endl;
        }
    } while (opcion != 4);

}

void ingresarNombresJugadores(string &nombreJ1, string &nombreJ2) {
    cout << "Ingrese el nombre del primer jugador: " <<endl;
    cin >> nombreJ1;
    cout << "Ingrese el nombre del segundo jugador: " <<endl;
    cin >> nombreJ2;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //esto ignora el buffer para no tener problemas con el limpiar pantalla
}

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

void  tirarD12(int dadosD12[2]) {
    //Se tiran los dados de 12 caras y se muestra por pantalla cuales son
    dadosD12[0] = rand()%12+1;
    dadosD12[1] = rand()%12+1;
    cout << "tu primer dado es: " << dadosD12[0] << endl;
    imprimirDadoD12(dadosD12[0]);
    cout << endl;
    cout << "y el segundo dado es: "<< dadosD12[1] << endl;
    imprimirDadoD12(dadosD12[1]);
    cout << endl;
    cout << "+--------------------------------------------------------------+" << endl;
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
        cin >> seleccion;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //esto ignora el buffer para no tener problemas con el limpiar pantalla

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

void limpiarPantalla() {
    //Esta funcion tiene una pausa hasta que se presione una tecla, luego hace un for que imprime 100 saltos de linea
    cout << "Presiona Enter para continuar..." << endl;
    cin.get();
    for (int i = 0; i < 100; ++i) {
        std::cout << std::endl;
    }
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

void confirmarGanador(int puntaje[2], string posicion[2], int mejorPuntuacion, string mejorJugador) {
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

void imprimirDadoD12(int valor) {
    const string caras[12] = {
        // 1
        "+---------+\n"
        "|         |\n"
        "|    o    |\n"
        "|         |\n"
        "+---------+",

        // 2
        "+---------+\n"
        "| o       |\n"
        "|         |\n"
        "|       o |\n"
        "+---------+",

        // 3
        "+---------+\n"
        "| o       |\n"
        "|    o    |\n"
        "|       o |\n"
        "+---------+",

        // 4
        "+---------+\n"
        "| o     o |\n"
        "|         |\n"
        "| o     o |\n"
        "+---------+",

        // 5
        "+---------+\n"
        "| o     o |\n"
        "|    o    |\n"
        "| o     o |\n"
        "+---------+",

        // 6
        "+---------+\n"
        "| o  o  o |\n"
        "|         |\n"
        "| o  o  o |\n"
        "+---------+",

        // 7
        "+---------+\n"
        "| o  o  o |\n"
        "|    o    |\n"
        "| o  o  o |\n"
        "+---------+",

        // 8
        "+---------+\n"
        "| o  o  o |\n"
        "| o     o |\n"
        "| o  o  o |\n"
        "+---------+",

        // 9
        "+---------+\n"
        "| o  o  o |\n"
        "| o  o  o |\n"
        "| o  o  o |\n"
        "+---------+",

        // 10
        "+---------+\n"
        "|o o o o o|\n"
        "|         |\n"
        "|o o o o o|\n"
        "+---------+",

        // 11
        "+---------+\n"
        "|o o o o o|\n"
        "|    o    |\n"
        "|o o o o o|\n"
        "+---------+",

        // 12
        "+---------+\n"
        "|o o o o o|\n"
        "|o o o o o|\n"
        "|o o o o o|\n"
        "+---------+"
    };

    cout << caras[valor - 1] << endl;
}

void modificarEstadistica(int puntaje, string posicion, int &mejorPuntuacion, string &mejorJugador) {
    if (puntaje > mejorPuntuacion) {
        mejorPuntuacion = puntaje;
        mejorJugador = posicion;
    }
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


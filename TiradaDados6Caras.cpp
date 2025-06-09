#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

void lanzarDados6Caras(int vec[], int dados){
    int i;
    srand(time(0));
    for(i=0; i<dados; i++){
       vec[i] = rand() % 6 + 1;
    }
}
void mostrarDados6Caras(int vec[], int dados){
    int i;
    for(i=0; i<dados; i++){
        cout << "El valor de dado " << i+1 << " es: " << vec[i] << endl;
    }
}

void elegirDados6Caras(int vec[], int dados){
    int dado, posicion=0;
    cout << "Elija el valor de un dado o 0 si quiere terminar la jugada" << endl; // el 0 deberia indicar que la jugada no es exitosa
    cin >> dado;                                                                  // aca solo corta el bucle
    while (dado != 0 && posicion<dados){
        vec[posicion] = dado;
        posicion++;
        cout << "Elija un dado o 0 si quiere terminar la jugada" << endl; // el 0 deberia indicar que la jugada no es exitosa
        cin >> dado;                                                       // aca solo corta el bucle
    }
}
 void mostrarDadosElegidos(int vec[], int dados){
    int i;
    cout << "Combinacion elegida " << endl;
    for(i=0; i<dados; i++){
        if (vec[i] != 0 ){
            cout << vec[i] << endl;
        }
    }
}

int main(){

    int dadosStock;
    int vdadosStock[11]{};
    int vdadosElegidos[11]{};

    cout << "Ingrese cantidad de dados: "; // En vez de ingresar, debería ser una variable que se obtiene de la suma de
    cin >> dadosStock;                     // dados stock y los dados que le pasa el otro jugador

    lanzarDados6Caras(vdadosStock,dadosStock); // Se envía un vector vacio y la dimension, la funcion modifica el contenido del vector
    mostrarDados6Caras(vdadosStock,dadosStock); // Se muestra el contenido del vector con un numero de dado
    elegirDados6Caras(vdadosElegidos,dadosStock); // Segun el TP se deberian sumar automaticamente al elegirlos
    mostrarDadosElegidos(vdadosElegidos,dadosStock); // muestra los valores elegidos

    return 0;
}

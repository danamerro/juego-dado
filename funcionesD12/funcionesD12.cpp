#include "funcionesD12.h"
#include <iostream>

using namespace std;

void tirarD12(int dadosD12[2]);
void imprimirDadoD12(int valor);

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
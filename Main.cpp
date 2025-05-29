#include <iostream>

using namespace std;

void menu();

int main() {
    menu();
    return 0;
}

void menu() {
    int opcion;

    do{
        system("cls");
        cout << endl;
        cout << "ENFRENDADOS" << endl;
        cout << "--------------" << endl;
        cout << "1 - JUGAR" << endl;
        cout << "2 - ESTADISTICAS" << endl;
        cout << "3 - CREDITOS" << endl;
        cout << "--------------" << endl;
        cout << "0 - SALIR" << endl;
        cout << "Elija opcion: " << endl;
        cin >> opcion;

        switch (opcion){
            case 1:
                cout << endl;
            cout << "Ud eligio Jugar" << endl;
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
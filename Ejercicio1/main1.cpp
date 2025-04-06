#include <iostream>
#include "Tiempo.hpp"
// Para compilar: g++ Tiempo.hpp Tiempo.cpp  main1.cpp -o run
// Para correrlo: ./run


using namespace std;

int main() {
    Tiempo t;
    int opcionI;

    cout << "=== MENÚ DE INICIO ===" << endl;
    cout << "1. Solo Hora" << endl;
    cout << "2. Hora y Minutos" << endl;
    cout << "3. Hora, Minutos y Segundos" << endl;
    cout << "4. Hora, Minutos, Segundos y Meridiano" << endl;
    cout << "Seleccionea una opción: ";
    cin >> opcionI;

    int h = 0, m = 0, s = 0;
    char meridiano;
    bool ap = true;

    if (opcionI >= 1) {
        cout << "Ingresa la hora (entre 1-12): ";
        cin >> h;
        while (!t.validarH(h)) {
            cout << "Hora inválida. Intentalo otra vez: ";
            cin >> h;
        }
    }
    if (opcionI >= 2) {
        cout << "Ingresa los minutos (entre 0-59): ";
        cin >> m;
        while (!t.validarM(m)) {
            cout << "Minutos inválidos. Intentalo otra vez: ";
            cin >> m;
        }
    }
    if (opcionI >= 3) {
        cout << "Ingresa los segundos (entre 0-59): ";
        cin >> s;
        while (!t.validarS(s)) {
            cout << "Segundos inválidos. Intentalo otra vez: ";
            cin >> s;
        }
    }
    if (opcionI == 4) {
        cout << "Ingresa 'a' para AM o 'p' para PM: ";
        cin >> meridiano;
        while (meridiano != 'a' && meridiano != 'p') {
            cout << "Opción inválida. Ingresa 'a' o 'p': ";
            cin >> meridiano;
        }
        ap = (meridiano == 'a');
    }

    t = Tiempo(h, m, s, ap);

    int opcion = 0;
    do {
        cout << "\n=== MENÚ ===" << endl;
        cout << "1. Ver hora en formato 12h" << endl;
        cout << "2. Ver hora en formato 24h" << endl;
        cout << "3. Modificar hora" << endl;
        cout << "4. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                t.show12h();
                break;
            case 2:
                t.show24h();
                break;
            case 3: {
                cout << "Ingresa la hora (entre 1-12): ";
                cin >> h;
                while (!t.validarH(h)) {
                    cout << "Hora inválida. Intentalo otra vez: ";
                    cin >> h;
                }

                cout << "Ingresa los minutos (entre 0-59): ";
                cin >> m;
                while (!t.validarM(m)) {
                    cout << "Minutos inválidos. Intentalo otra vez: ";
                    cin >> m;
                }

                cout << "Ingresa los segundos (entre 0-59): ";
                cin >> s;
                while (!t.validarS(s)) {
                    cout << "Segundos inválidos. Intentalo otra vez: ";
                    cin >> s;
                }

                cout << "Ingrese 'a' para AM o 'p' para PM: ";
                cin >> meridiano;
                while (meridiano != 'a' && meridiano != 'p') {
                    cout << "Opción inválida. Ingresa 'a' o 'p': ";
                    cin >> meridiano;
                }
                ap = (meridiano == 'a');

                t.setH(h);
                t.setM(m);
                t.setS(s);
                t.setAP(ap);
                break;
            }
            case 4:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opción inválida.\n";
        }

    } while (opcion != 4);

    return 0;
}

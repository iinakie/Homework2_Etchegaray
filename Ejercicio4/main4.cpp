#include <iostream>
#include "clases.hpp"  

using namespace std;

// Para compilar: g++ clases.hpp funciones4.cpp  main4.cpp -o run
// Para correrlo: ./run

int main() {
    CajaA caja("Inaki", 300.0);
    CuentaC corriente("Inaki", 150.0);

    cout << "--- ESTADO INICIAL ---" << endl;
    caja.mostrarInfo();
    corriente.mostrarInfo();
    cout << endl;

    // Prueba 1: Retiro normal desde cuenta corriente
    cout << "--- RETIRO SOLO DESDE CUENTA CORRIENTE (100$) ---" << endl;
    corriente.retirar(100.0, &caja);
    caja.mostrarInfo();
    corriente.mostrarInfo();
    cout << endl;

    // Prueba 2: Retiro  de ambas cuentas (200$) → se necesita 150 (lo que queda) + 50 de la caja
    cout << "--- RETIRO COMBINADO (200$) ---" << endl;
    corriente.retirar(200.0, &caja);
    corriente.mostrarInfo();
    caja.mostrarInfo();
    cout << endl;

    // Prueba 3: Retiro Imposible (500$) → no alcanza ni con ambas cuentas
    cout << "--- RETIRO IMPOSIBLE (500$) ---" << endl;
    corriente.retirar(500.0, &caja);
    corriente.mostrarInfo();
    caja.mostrarInfo();
    cout << endl;

    // Prueba 4: mostrar info de la caja más de 2 veces para activar penalización
    cout << "--- Solo Penalizacion por mostrar la info de la caja varias veces ---" << endl;
    caja.mostrarInfo();  // 1
    caja.mostrarInfo();  // 2
    caja.mostrarInfo();  // 3 
    caja.mostrarInfo();  // 4 
    cout << endl;

    // Mostrar estado final
    cout << "--- ESTADO FINAL ---" << endl;
    corriente.mostrarInfo();
    caja.mostrarInfo();

    return 0;
}

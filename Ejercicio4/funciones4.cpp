#include "clases.hpp"
#include <iostream>
using namespace std;

// -------------CuentaBancaria------------

CuentaBancaria :: CuentaBancaria(string t, double saldoI) : titularC(t), balance(saldoI){}

void CuentaBancaria :: depositar(double cantidad){balance += cantidad;}

void CuentaBancaria :: mostrarInfo(){
    cout << "Nombre del titular de la cuenta: " << titularC << endl;
    cout << "Balance total de la cuenta: " << balance << endl;
}


// -------------Caja de Ahorro (CajaA)------------

CajaA :: CajaA(string t, double saldoI): CuentaBancaria(t,  saldoI){}

void CajaA :: retirar(double cantidad){
    if(cantidad > balance){
        cout << "No tenes tanto dinero en tu cuenta" << endl;
    } else{
        balance -= cantidad;
        cout << "Retiro exitoso de" << cantidad << "$" << endl;
    }
}

void CajaA::mostrarInfo() {
    contador++;
    cout << "--- Caja de Ahorro ---" << endl;
    CuentaBancaria::mostrarInfo();
    if (contador > 2) {
        cout << "Se aplicó un descuento de $20 por exceso de consultas." << endl;
        balance -= 20;
    }
}


// -------------Cuenta Corriente (CuentaC)------------


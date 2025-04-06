#include "clases.hpp"
#include <iostream>
using namespace std;

/*
Primero en CuentaBancaria, en el constructor, se guardan el nombre del titular y el saldo inicial. En depositar() simplemente suma la cantidad al 
balance. En mostrarInfo() muestra el nombre del titular y cuánta plata tiene en la cuenta.

Después en CajaA (Caja de Ahorro). En retirar(), si la plata que querés sacar es más de la que tenés, te avisa. Si no, te la descuenta. En 
mostrarInfo() muestra los datos igual que CuentaBancaria, pero además tiene un contador que suma cada vez que se consultay si pasás más de 2 
consultas, te descuenta $20 automáticamente del saldo (esto es como una penalización por consultar muchas veces), por eso uso mutable int contador.

En la CuentaC (Cuenta Corriente). EN mostrarInfo() muestro los datos básicos, como en la cuenta base. En retirar() es más especial, ya que, 
primero revisa si la cantidad es negativa (lo rechaza). Si hay suficiente saldo, lo descuenta normal y si no alcanza pero hay una caja de ahorro 
(CajaA) que alcanza con el saldo combinado, hace un retiro mixto: saca lo que puede de CuentaC, y el resto de la CajaA, pero si no hay suficiente 
entre las dos, te dice que no hay saldo.
*/

// -------------CuentaBancaria------------

CuentaBancaria :: CuentaBancaria(string t, double saldoI) : titularC(t), balance(saldoI){}

void CuentaBancaria :: depositar(double cantidad){balance += cantidad;}

void CuentaBancaria :: mostrarInfo(){
    cout << "Nombre del titular de la cuenta: " << titularC << endl;
    cout << "Balance total de la cuenta: " << balance << endl;
}


// -------------Caja de Ahorro (CajaA)------------

CajaA :: CajaA(string t, double saldoI): CuentaBancaria(t,  saldoI){}

void CajaA :: retirar(double cantidad, CajaA* caja){
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

CuentaC :: CuentaC(string t, double saldoI) : CuentaBancaria(t, saldoI){}

void CuentaC :: mostrarInfo(){
    cout << "--- Cuenat Corriente ---" << endl;
    CuentaBancaria::mostrarInfo();
}

void CuentaC::retirar(double cantidad, CajaA* caja) {
    if (cantidad < 0) {
        cout << "No se puede retirar dinero siendo negativo el numero" << endl;
        return;
    }
    if (cantidad <= balance) {
        balance -= cantidad;
        cout << "Se retiro " << cantidad << "$ desde tu Cuenta Corriente." << endl;
    } else if (caja && cantidad <= balance + caja->balance) {
        double faltante = cantidad - balance;
        balance = 0;
        caja->balance -= faltante;
        cout << "Retiro combinado posible. Se retiro " << cantidad << "$ de la Caja de Ahorro." << endl;
    } else {
        cout << "No tenes dinero suficiente en tus cuentas." << endl;
    }
}


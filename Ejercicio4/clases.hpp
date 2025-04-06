#include <iostream>
#include <vector>

using namespace std;

/*
Primero defino CuentaBancaria (clase base) que tiene dos datos: el balance (cuánta plata hay) y el nombre del titular. Tiene un constructor para 
crear la cuenta con nombre y saldo inicial. Tiene un método para depositar (sumar plata). Después tiene una función virtual retirar() para sacar 
plata, que es pura (= 0), o sea: todas las subclases la tienen que implementar sí o sí. Y también tiene un método para mostrar la info de la cuenta.

Después defino CajaA (hereda de CuentaBancaria) esta tiene un contador de veces que se pidió la info, gracias al atributo mutable. Tiene una 
función retirar() que se implementa para esta clase. También tiene una función descontar(), que puede usarse desde otra clase. Y por ultimo le doy
acceso especial a CuentaC con friend class CuentaC; para que pueda acceder a sus atributos privados si hace falta.

Y en la clase CuentaC (también hereda de CuentaBancaria) que tiene su propia versión de retirar() y de mostrarInfo(), to esto gracias al friend 
que puede acceder directamente a los atributos privados de CajaA, por ejemplo para modificarla cuando interactúan.
*/


class CajaA;

class CuentaBancaria{
    protected:
        double balance;
        string titularC;
    public:
        CuentaBancaria(string nombre, double saldoI);
        void depositar(double cantidad);
        virtual void retirar(double cantidad, CajaA* caja = nullptr) = 0;
        virtual void mostrarInfo();
};

class CajaA : public CuentaBancaria{
    protected:
        mutable int contador = 0;
        friend class CuentaC;  

    public:
        CajaA(string nombre, double saldoI);
        void retirar(double cantidad, CajaA* caja = nullptr) override;
        void mostrarInfo() override;
        void descontar();

};

class CuentaC : public CuentaBancaria{    
    public:
        CuentaC(string nombre, double saldoI);
        void retirar(double cantidad, CajaA* caja = nullptr) override;
        void mostrarInfo();
        
};
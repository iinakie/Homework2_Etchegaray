#include <iostream>
#include <vector>

using namespace std;

class CuentaBancaria{
    protected:
        string titularC;
        double balance;
    public:
        CuentaBancaria(string nombre, double saldoI);
        void depositar(double cantidad);
        virtual void retirar(double cantidad) = 0;
        virtual void mostrarInfo();
};

class CajaA : CuentaBancaria{
    protected:
        mutable int contador = 0;
        friend class CuentaCorriente; 

    public:
        CajaA(string nombre, double saldoI);
        void retirar(double cantidad) override;
        void mostrarInfo() override;
        void descontar();

};

class CuentaC : CuentaBancaria{    
    public:
        CuentaC(string nombre, double saldoI);
        void retirar(double cantidad);
        void retirar(double cantidad, CajaA& caja);
        void mostrarInfo();
};
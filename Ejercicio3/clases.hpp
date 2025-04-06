#include <iostream>
#include <string>
using namespace std;

/*
Primero creo la Clase Numero (abstracta) esta es la clase base que representa un número en general. Tiene funciones virtuales puras, 
lo que significa que todas las subclases están obligadas a implementarlas. Estas son: suma(), resta(), multiplicacion() 
y todas hacen operaciones entre números, y tambien toString() que devuelve el número como texto(string).
Segundo creo la Clase Entero (que hereda de Numero) la cual guarda un número entero (int) y tiene su propio getV() para acceder al valor.
Esta implementa las 3 operaciones y el toString() (aunque todavía no están desarrolladas en este código, están declaradas)
Tercera creo la Clase Real (también hereda de Numero) la cual guarda un número real (double) y también implementa todas las funciones igual que 
Entero, pero usando su propio tipo de dato
Y por ultimo hago la Clase Complejo (también hereda de Numero), esta representa un número complejo (tiene parte real y parte imaginaria), entonces tiene dos valores: 
real y imaginario. Al igual que las otras implementa las operaciones suma, resta, multiplicación y el toString() a su manera
*/


class Numero{
    public:
        virtual Numero* suma(const Numero* otro) const = 0;
        virtual Numero* resta(const Numero* otro) const = 0;
        virtual Numero* multiplicacion(const Numero* otro) const = 0;
        virtual string toString() const = 0;

};

class Entero : public Numero{
    private:
        int valor;
    public:
        Entero(int v);
        int getV() const;
        Numero* suma(const Numero* otro) const override;
        Numero* resta(const Numero* otro) const override;
        Numero* multiplicacion(const Numero* otro) const override;
        virtual string toString() const override;
};

class Real : public Numero{
    private:
        double valor;
    public:
        Real(double v);
        double getV() const;
        Numero* suma(const Numero* otro) const override;
        Numero* resta(const Numero* otro) const override;
        Numero* multiplicacion(const Numero* otro) const override;
        virtual string toString() const override;
};

class Complejo : public Numero{
    private:
        double real;
        double imaginario;
    public:
        Complejo(double r, double i);
        double getR() const;
        double getI() const;
        Numero* suma(const Numero* otro) const override;
        Numero* resta(const Numero* otro) const override;
        Numero* multiplicacion(const Numero* otro) const override;
        virtual string toString() const override;
};


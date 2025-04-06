#include <iostream>
#include <vector>
#include <memory>
#include "clases.hpp"



int main() {
    // Operaciones con los ENTEROS
    Entero a(2), b(4);
    Numero* suma = a.suma(&b);
    Numero* resta = a.resta(&b);
    Numero* multiplicacion = a.multiplicacion(&b);

    cout << "Los enteros seleccionados y sus opeaciones:" << endl;
    cout << "a = " << a.toString() << " y b = " << b.toString() << endl;
    cout << "La suma queda: " << suma->toString() << endl;
    cout << "La resta queda: " << resta->toString() << endl;
    cout << "La multiplicacion queda: " << multiplicacion->toString() << endl;

    delete suma;
    delete resta;
    delete multiplicacion;

    // Operaciones con los REALES
    Real r1(2.0), r2(4.2);
    Numero* rsuma = r1.suma(&r2);
    Numero* rresta = r1.resta(&r2);
    Numero* rmultiplicacion = r1.multiplicacion(&r2);

    cout << "Los reales seleccionados y sus opeaciones:" << endl;
    cout << "r1 = " << r1.toString() << " y r2 = " << r2.toString() << endl;
    cout << "La suma queda: " << rsuma->toString() << endl;
    cout << "La resta queda: " << rresta->toString() << endl;
    cout << "La multiplicacion queda: " << rmultiplicacion->toString() << endl;

    delete rsuma;
    delete rresta;
    delete rmultiplicacion;

    // Operaciones con los COMPLEJOS
    Complejo c1(2.3, 2.7), c2(4.3, 4.7);
    Numero* csuma = c1.suma(&c2);
    Numero* cresta = c1.resta(&c2);
    Numero* cmultiplicacion = c1.multiplicacion(&c2);

    cout << "Los complejos seleccionados y sus opeaciones:" << endl;
    cout << "c1 = " << c1.toString() << " y c2 = " << c2.toString() << endl;
    cout << "La suma queda: " << csuma->toString() << endl;
    cout << "La resta queda: " << cresta->toString() << endl;
    cout << "La multiplicacion queda: " << cmultiplicacion->toString() << endl;

    delete csuma;
    delete cresta;
    delete cmultiplicacion;
}
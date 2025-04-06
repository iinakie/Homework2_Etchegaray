#include "clases.hpp"
#include <sstream>
#include <cmath>
#include <iomanip>

/*
En la clase de Entero guardo un int. Las operaciones (suma, resta, multiplicacion) solo se hacen si el otro número también es Entero que para eso 
uso dynamic_cast y verifico si funciona, y si no es del mismo tipo, devuelvo nullptr. Después, el toString() convierte el número entero a texto 
con to_string.
En la clase Real guardo un double. Las operaciones funcionan igual que con Entero, pero usando números reales y también uso dynamic_cast para 
asegurarse de que el otro número es un Real. Después en toString() devuelve el número como string (aunque se puede mejorar con setprecision si 
se quiere redondear).
En la clase Complejo guardo dos double: uno para la parte real y otro para la imaginaria. La suma y resta hacen operaciones normales con números 
complejos. La multiplicación por ahora está simplificada (no hace la multiplicación real entre complejos, sino real * real y imag * imag). Y el
toString() devuelve el número en formato "a + bi" como string.
*/


// -------------ENTEROS------------

Entero :: Entero(int v) : valor (v){}

int Entero :: getV() const { return valor;}

Numero* Entero :: suma(const Numero* otro) const{
    const Entero* e = dynamic_cast<const Entero*>(otro);
    if (e) return new Entero(valor + e->getV());
    return nullptr;
};

Numero* Entero :: resta(const Numero* otro) const{
    const Entero* e = dynamic_cast<const Entero*>(otro);
    if (e) return new Entero(valor - e->getV());
    return nullptr;
}

Numero* Entero :: multiplicacion(const Numero* otro) const{
    const Entero* e = dynamic_cast<const Entero*>(otro);
    if (e) return new Entero(valor * e->getV());
    return nullptr;
}

string Entero :: toString() const{
    return to_string(valor);
};


// -------------REALES------------

Real :: Real(double v) : valor (v){}

double Real ::getV() const { return valor;}

Numero* Real ::suma(const Numero* otro) const{
    const Real* r = dynamic_cast<const Real*>(otro);
    if (r) return new Real(valor + r->getV());
    return nullptr;
};
Numero* Real ::resta(const Numero* otro) const{
    const Real* r = dynamic_cast<const Real*>(otro);
    if (r) return new Real(valor - r->getV());
    return nullptr;
};
Numero* Real ::multiplicacion(const Numero* otro) const{
    const Real* r = dynamic_cast<const Real*>(otro);
    if (r) return new Real(valor * r->getV());
    return nullptr;
};
string Real :: toString() const{
    return to_string(valor);
};

// -------------COMPLEJOS------------

Complejo :: Complejo(double r, double i) : real (r), imaginario(i){}

double Complejo ::getR() const { return real;}
double Complejo ::getI() const { return imaginario;}

Numero* Complejo ::suma(const Numero* otro) const{
    const Complejo* c = dynamic_cast<const Complejo*>(otro);
    if (c) return new Complejo(real + c->getR(), imaginario + c->getI());
    return nullptr;
};
Numero* Complejo ::resta(const Numero* otro) const{
    const Complejo* c = dynamic_cast<const Complejo*>(otro);
    if (c) return new Complejo(real - c->getR(), imaginario - c->getI());
    return nullptr;
};
Numero* Complejo ::multiplicacion(const Numero* otro) const{
    const Complejo* c = dynamic_cast<const Complejo*>(otro);
    if (c) return new Complejo(real * c->getR(), imaginario * c->getI());
    return nullptr;
};
string Complejo :: toString() const{
    return to_string(real) + " + " + to_string(imaginario) + "i";
};
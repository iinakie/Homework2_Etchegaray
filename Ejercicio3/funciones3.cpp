#include "clases.hpp"
#include <sstream>
#include <cmath>
#include <iomanip>


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
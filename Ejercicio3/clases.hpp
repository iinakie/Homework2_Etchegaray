#include <iostream>
#include <string>
using namespace std;

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


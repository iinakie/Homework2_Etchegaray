#include <iostream>

using namespace std;

class Tiempo{
    private:
        int hora;
        int minuto;
        int segundo;
        bool es_am_pm;
    
    public:
        Tiempo(int h = 0, int m = 0, int s = 0, bool ap = false);    

        void setH(int h);
        void setM(int m);
        void setS(int s);
        void setAP(bool ap);

        int getH();
        int getM();
        int getS();
        bool getAP();

        void show12h();
        void show24h();

        bool validarH(int h);
        bool validarM(int m);
        bool validarS(int s);
    };
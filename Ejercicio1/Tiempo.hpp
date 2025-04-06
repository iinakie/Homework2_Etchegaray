#include <iostream>

using namespace std;
/*
Acá lo que hago es declarar la clase Tiempo. O sea, le digo al programa qué cosas va a tener esta clase.
Tengo 4 datos guardados: la hora, los minutos, los segundos y si es a.m. o p.m. (eso es bool).
En la parte pública declaro un constructor, que es lo que se usa para crear un objeto Tiempo. Le puedo pasar valores o usar los valores por defecto.
Después tengo funciones para "setear" (cambiar) la hora, minutos, segundos y si es am o pm. También tengo funciones para obtener (los get) esos datos.
Después, los show12h() y show24h() sirven para mostrar la hora en formato de 12 o 24 horas.
Por último, tengo unas funciones (validarH, validarM, validarS) que uso para asegurarme de que los valores que me pasan son válidos.
*/

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
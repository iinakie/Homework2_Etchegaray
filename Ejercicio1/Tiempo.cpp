#include "Tiempo.hpp"
#include <iostream>
#include <iomanip>
/*
En este archivo hago la parte que define cómo funcionan las funciones de la clase Tiempo.Acá están todas las instrucciones reales de lo que 
hacen las cosas.
- El constructor sirve para crear un objeto Tiempo con hora, minutos, segundos y si es a.m. o p.m.
- Los métodos setH, setM, setS y setAP sirven para cambiar los valores de hora, minuto, segundo y si es a.m. o p.m.
- Los métodos getH, getM, getS y getAP me devuelven esos valores.
- Para mostrar las horas hice los show:
   - show12h() muestra la hora en formato tipo “03h, 14m, 42s am”.
   - show24h() muestra la hora como si fuera de 24 horas, por ejemplo “13:14:42”.
- Las funciones validarH, validarM y validarS sirven para chequear si los valores que pongo son válidos 
(por ejemplo que la hora no sea 25 o los minutos 80).
*/

Tiempo :: Tiempo(int h, int m, int s, bool ap){
    hora = h;
    minuto = m;
    segundo = s;
    es_am_pm = ap;
}

void Tiempo::setH(int h){ hora = h;}
void Tiempo::setM(int m){ minuto = m;}
void Tiempo::setS(int s){ segundo = s;}
void Tiempo::setAP(bool ap){ es_am_pm = ap;}

int Tiempo::getH(){ return hora;}
int Tiempo::getM(){ return minuto;}
int Tiempo::getS(){ return segundo;}
bool Tiempo::getAP(){ return es_am_pm;}

void Tiempo::show12h(){
    cout << setw(2) << setfill('0') << hora << "h, "
         << setw(2) << setfill('0') << minuto << "m, "
         << setw(2) << setfill('0') << segundo << "s "
         << (es_am_pm? "am":"pm") << endl;
}

void Tiempo::show24h(){
    int t24 = hora;

    if(!es_am_pm && hora != 12){
        t24 += 12;
    } else if (es_am_pm && hora == 12){
        t24 = 0;
    }

    cout << setw(2) << setfill('0') << t24 << ":"
         << setw(2) << setfill('0') << minuto << ":"
         << setw(2) << setfill('0') << segundo << endl;
}

bool Tiempo::validarH(int h){ return h >= 1 && h <= 12;}
bool Tiempo::validarM(int m){ return m >= 0 && m <= 60;}
bool Tiempo::validarS(int s){ return s >= 0 && s <= 60;}



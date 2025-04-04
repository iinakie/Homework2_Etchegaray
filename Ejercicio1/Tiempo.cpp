#include "Tiempo.hpp"
#include <iostream>
#include <iomanip>

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



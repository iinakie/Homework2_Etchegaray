#include "Clases.hpp"
#include <iostream>
#include <map>
#include <vector>

Estudiante :: Estudiante(string n, int l){
    nombreCom = n;
    legajo = l;
}

string Estudiante ::getN(){ return nombreCom;}
int Estudiante ::getL(){ return legajo;}
float Estudiante ::Promedio(){
    if(Notas.empty()) return 0.0f;

    int suma = 0;

    for(const auto& par : Notas){
        suma += par.second;
    }
    float promedio = static_cast<float> (suma) / Notas.size();

    return promedio;
}
void Estudiante ::agregarNota(string curso, float Nota){ Notas[curso] = static_cast<int> (Nota);}

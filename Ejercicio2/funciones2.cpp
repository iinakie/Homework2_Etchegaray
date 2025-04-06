#include "Clases.hpp"
#include <iostream>
#include <map>
#include <vector>

Estudiante :: Estudiante(string n, int l){
    nombre = n;
    legajo = l;
}

string Estudiante ::getN() const { return nombre;}
int Estudiante ::getL() const { return legajo;}

float Estudiante ::Promedio(){
    if(Notas.empty()) return 0.0f;

    int suma = 0;

    for(const auto& par : Notas){
        suma += par.second;
    }
    float promedio = static_cast<float> (suma) / Notas.size();

    return promedio;
}

void Estudiante::agregarNota(std::string curso, float nota) {
    for (auto& par : Notas) {
        if (par.first == curso) {
            par.second = nota; 
            return;
        }
    }
    Notas.push_back({curso, nota});
}


Curso::Curso(string materia) {
    N_materia = materia;
}

Curso::Curso(const Curso& otroCurso)
    : N_materia(otroCurso.N_materia), estudiantes(otroCurso.estudiantes) {
    /*
        COPIA (shallow copy):
        Este constructor copia el nombre del curso y la lista de punteros a estudiantes. Use este tipo de copia porque, no se crean nuevos objetos 
        Estudiante, sino que se comparten los mismos punteros y esto permite que varios cursos apunten a los mismos estudiantes.
    */
}

void Curso :: inscribirE(Estudiante* e){
    if(lleno_s_n()){
        cout << "En este curso ya no entran mas estudiantes." << endl;
        return;
    }
    if(inscripto_s_n(e->getL())){
        cout << "Este estudiante ya esta inscripto en este curso." << endl;
        return;
    }
    estudiantes.push_back(e);
    cout << "Este estudiante ha sido inscripto en el curso." << endl;

}
void Curso :: desincribirE(Estudiante* e){
    for (auto Eeliminar = estudiantes.begin(); Eeliminar != estudiantes.end(); ++Eeliminar) {
        if ((*Eeliminar)->getL() == e->getL()) {
            estudiantes.erase(Eeliminar);
            cout << "Este estudiante ha sido desinscripto." << endl;
            return;
        }
    }
    cout << "Este estudiante no ha sido encontrado en el curso." << endl;
}

bool Curso :: inscripto_s_n( int legajo) const{
    for(const Estudiante* e : estudiantes){
        if(e->getL() == legajo) return true;
    }
    return false;
}

bool Curso :: lleno_s_n()const {
    return estudiantes.size() >= lugares;
}

void Curso :: imprimirEorden() const{
    vector<const Estudiante*> copy = estudiantes;
    sort(copy.begin(), copy.end(), [](const Estudiante* a, const Estudiante* b) {
        return *a < *b; 
    });
    cout << "Los estudiantes del curso " << N_materia << "ordenados alfabeticamente son:" << endl;

    for(const Estudiante* e : copy){
        cout << *e << endl;
    }
}

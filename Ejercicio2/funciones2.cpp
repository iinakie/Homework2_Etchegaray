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

Curso::Curso(const Curso& otroCurso) {
    /*
        Esta es una copia del objeto Curso. Donde se copian los punteros a los mismos objetos Estudiante y no se crean nuevas 
        instancias de Estudiante. Esto puede hacer que varios cursos compartan los mismos estudiantes.

        IMPORTANTE: Como los estudiantes son compartidos, no debemos hacer delete
        en el destructor ni asumir propiedad exclusiva.
    */
    N_materia = otroCurso.N_materia;
    estudiantes = otroCurso.estudiantes; // copia 
}
void Curso :: inscribirE(Estudiante* e){
    if(lleno_s_n()){
        cout << "En este curso ya no entran mas estudiantes. /n";
        return;
    }
    if(inscripto_s_n(e->getL())){
        cout << "Este estudiante ya esta inscripto en este curso./n";
        return;
    }
    estudiantes.push_back(e);
    cout << "Este estudiante ha sido inscripto en el curso./n";

}
void Curso :: desincribirE(Estudiante* e){
    for (auto Eeliminar = estudiantes.begin(); Eeliminar != estudiantes.end(); ++Eeliminar) {
        if ((*Eeliminar)->getL() == e->getL()) {
            estudiantes.erase(Eeliminar);
            cout << "Este estudiante ha sido desinscripto.\n";
            return;
        }
    }
    cout << "Este estudiante no ha sido encontrado en el curso.\n";
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
    sort(copy.begin(), copy.end(), [](Estudiante*a, Estudiante*b){
        return a* < *b;
    });
    cout << "Los estudiantes del curso " << N_materia << "ordenados alfabeticamente son:/n";

    for(const Estudiante* e : copy){
        cout << *e << endl;
    }
}

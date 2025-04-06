#include "Clases.hpp"
#include <iostream>
#include <map>
#include <vector>

/*
En la Clase Estudiante el constructor guarda el nombre y legajo. Los "getters": getN() y getL() devuelven el nombre y legajo. Despues el 
Promedio() calcula el promedio de todas las notas que tiene el estudiante (las guarda como par: curso + nota). Ademas en agregarNota() permite 
agregar o actualizar una nota para un curso. Aca sobrecargo el operador < para poder ordenar estudiantes por nombre. Pero también sobrecargo el 
<< para que se pueda imprimir un estudiante con cout <<.

En la Clase Curso el constructor: guarda el nombre del curso. Y el constructor copia: hace una copia superficial (shallow copy), o sea que copia 
los punteros a los mismos estudiantes, no los estudiantes nuevos. Después el inscribirE() agrega un estudiante si no está ya inscripto y si hay 
lugar y, por el otro lado,desincribirE() lo busca por legajo y lo borra del vector si está. Después eninscripto_s_n() verifico si un estudiante con
ese legajo ya está en el curso. Además en lleno_s_n() verifico si ya hay 20 estudiantes inscriptos. Por último en imprimirEorden() hago una copia 
del vector de estudiantes y los ordena alfabéticamente usando sort() y el operador <.
*/


Estudiante :: Estudiante(string n, int l){
    nombre = n;
    legajo = l;
}

string Estudiante ::getN() const { return nombre;}
int Estudiante ::getL() const { return legajo;}

float Estudiante ::Promedio() const{
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

bool Estudiante::operator<(const Estudiante& otro) const {
    return nombre < otro.nombre; // o por legajo si preferís
}

ostream& operator<<(ostream& os, const Estudiante& e) {
    os << "Nombre: " << e.nombre
       << " | Legajo: " << e.legajo
       << " | Promedio: " << e.Promedio();
    return os;
}


Curso::Curso(string materia) {
    N_materia = materia;
}

Curso::Curso(const Curso& otroCurso) : N_materia(otroCurso.N_materia), estudiantes(otroCurso.estudiantes) {
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

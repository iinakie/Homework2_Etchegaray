#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

/*
En este archivo tengo dos clases: una es para representar un estudiante y la otra es para un curso.

La Clase Estudiante tiene nombre, legajo y una lista de notas (que está hecha con un vector de pares: nombre del curso y nota).
Hay funciones para:
- Obtener nombre y legajo
- Calcular el promedio de todas sus notas
- Agregar una nota nueva para un curso
También tiene una sobrecarga del operador < para poder comparar estudiantes (la uso para ordenarlos alfabéticamente) y una sobrecarga del operador
<< para poder imprimir el estudiante con cout << estudiante.

La Clase Curso tiene un nombre de materia y una lista de punteros a estudiantes (vector<const Estudiante*>). El curso tiene un máximo de 20 lugares.
Las funciones que tiene son para:
- Inscribir o desinscribir estudiantes
- Ver si un estudiante está en el curso (por legajo)
- Ver si el curso está lleno

Y por ultimo imprimo todos los estudiantes del curso ordenados alfabéticamente (uso std::sort y el operador < de Estudiante)
*/


class Estudiante{
    private:
        string nombre;
        int legajo;
        vector<std::pair<std::string, float>> Notas;
    
    public:
        Estudiante(string nombre, int legajo);
        string getN() const;
        int getL() const;
        float Promedio() const;

        void agregarNota(string curso, float Nota);

        bool operator<(const Estudiante& otro) const;
        friend ostream& operator<<(ostream& os, const Estudiante& e);

};

class Curso{
    private:
        string N_materia;
        vector< const Estudiante*> estudiantes;
        static const int lugares = 20;
        
    public:
        Curso(string materia);
        Curso(const Curso& curso);


        void inscribirE(Estudiante* e);
        void desincribirE(Estudiante* e);

        bool inscripto_s_n(int legajo) const;
        bool lleno_s_n() const;

        void imprimirEorden() const;
};
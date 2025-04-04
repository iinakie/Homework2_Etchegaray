#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

class Estudiante{
    private:
        string nombre;
        int legajo;
        vector<std::pair<std::string, float>> Notas;
    
    public:
        Estudiante(string nombre, int legajo);
        string getN() const;
        int getL() const;
        float Promedio();

        void agregarNota(string curso, float Nota);

};

class Curso{
    private:
        string N_materia;
        vector< const Estudiante*> estudiantes;
        static const int lugares = 20;
        
    public:
        Curso(string materia);
        Curso(Curso* curso);


        void inscribirE(Estudiante* e);
        void desincribirE(Estudiante* e);

        bool inscripto_s_n(int legajo) const;
        bool lleno_s_n() const;

        void imprimirEorden() const;
};
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Estudiante{
    private:
        string nombreCom;
        int legajo;
        map< string, int > Notas;    

    public:
        Estudiante(string nombre, int legajo);

        string getN();
        int getL();
        
        float Promedio();

        void agregarNota(string curso, float Nota);

};

class Curso{
    private:
        vector<Estudiante*> estudiantes;
        static const int lugares = 20;
        
    public:
        Curso();
        ~Curso();

        void inscribirE(Estudiante* e);
        void desincribirE(Estudiante* e);

        bool inscripto_s_n(int legajo);
        bool lleno_s_n();

        void imprimirEorden();
};
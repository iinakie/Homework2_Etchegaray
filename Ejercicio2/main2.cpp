#include <iostream>
#include <string>
#include "Clases.hpp"

using namespace std;

int main() {
    string nombreCurso;
    cout << "Ingrese el nombre del curso: ";
    getline(cin, nombreCurso);

    Curso curso1(nombreCurso);
    Curso cursoClonado(""); // objeto vacío por ahora

    int opcion;

    do {
        cout << "MENU PRINCIPAL" << endl;
        cout << "1. Inscribir un estudiante" << endl;
        cout << "2. Desinscribir un estudiante" << endl;
        cout << "3. Verificar si un estudiante está inscripto" << endl;
        cout << "4. Verificar si el curso está lleno" << endl;
        cout << "5. Imprimir estudiantes ordenados alfabeticamente" << endl;
        cout << "6. Clonar curso" << endl;
        cout << "7. Imprimir curso clonado" << endl;
        cout << "8. Salir del Programa" << endl;
        cout << "Seleccione una opción: " << endl;
        cin >> opcion;

        switch (opcion) {
            case 1: {
                string nombre;
                int legajo;
                cout << "Nombre del estudiante: " << endl;
                getline(cin, nombre);
                cout << "Legajo: " << endl;
                cin >> legajo;

                Estudiante* nuevo = new Estudiante(nombre, legajo);
                curso1.inscribirE(nuevo);
                break;
            }

            case 2: {
                int legajo;
                cout << "Ingrese legajo del estudiante a desinscribir: " << endl;
                cin >> legajo;

                // Creamos un objeto temporal solo con el legajo para buscar
                Estudiante temp("", legajo);
                curso1.desincribirE(&temp);
                break;
            }

            case 3: {
                int legajo;
                cout << "Ingrese legajo: ";
                cin >> legajo;
                cin.ignore();

                if (curso1.inscripto_s_n(legajo))
                    cout << "El estudiante está inscripto.\n";
                else
                    cout << "El estudiante NO está inscripto.\n";
                break;
            }

            case 4: {
                if (curso1.lleno_s_n())
                    cout << "El curso está lleno.\n";
                else
                    cout << "Aún hay lugares disponibles.\n";
                break;
            }

            case 5:
                curso1.imprimirEorden();
                break;

            case 6:
                cursoClonado = Curso(curso1); // usamos constructor copia
                cout << "Curso clonado exitosamente.\n";
                break;

            case 7:
                cursoClonado.imprimirEorden();
                break;

            case 8:
                cout << "Saliendo...\n";
                break;

            default:
                cout << "Opción inválida.\n";
                break;
        }

    } while (opcion != 8);

    return 0;
}

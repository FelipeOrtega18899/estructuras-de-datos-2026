#include <iostream>
#include <vector>
using namespace std;

struct Alumno {
    int matricula;
    string nombre;
    double promedio;
};

int buscarPorMatricula(vector<Alumno>& grupo, int matricula) {
    for (int i = 0; i < grupo.size(); i++) {
        if (grupo[i].matricula == matricula) {
            return i; //Si existe
        }
    }
    return -1;
}

bool agregarAlumno(vector<Alumno>& grupo, const Alumno& alumno) {
    if (buscarPorMatricula(grupo, alumno.matricula) != -1) {
        return false; //Ya existe;
    }
    grupo.push_back(alumno);
    return true;
};

int main() {
    vector<Alumno> grupo;
    int opcion;

    do {
        cout << "\n========================\n";
        cout << "Menu - vector<Alumno>";
        cout << "\n========================\n";
        cout << "1) Agregar alumno\n";
        cout << "2) Mostrar alumnos\n";
        cout << "3) Buscar alumno por matricula\n";
        cout << "4) Actualizar alumno\n";
        cout << "5) Eliminar alumno\n";
        cout << "6) Ordenar por promedio (desc)\n";
        cout << "7) Ordenar por promedio (asc)\n";
        cout << "8) Calcular promedio del grupo\n";
        cout << "0) Salir\n";
        cout << "Selecciona una opcion: ";
        cin >> opcion;

        if (opcion == 1) {
            Alumno tem_alumno;
            cout<<"--- Agregar alumno ---"<<endl;
            cout<<"Ingresa Matricula: ";
            cin >> tem_alumno.matricula;
            cin.ignore();

            cout<<"Ingresa nombre: ";
            getline(cin,tem_alumno.nombre);

            cout<<"Ingresa Promedio: ";
            cin >>tem_alumno.promedio;

            if (agregarAlumno(grupo, tem_alumno)) {
                cout<<"Alumno agregado correctamente.";
            } else {
                cout << "ERROR: Matricula existente.";
            }
        }

    } while (opcion != 0);

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Alumno {
    int matricula;
    string alumno;
    double promedio;
};

// Función auxiliar reutilizable
int BuscarPorMatricula(const vector<Alumno>& grupo, int matricula) {
    for (int i = 0; i < grupo.size(); i++) {
        if (grupo[i].matricula == matricula) {
            return i; // Retorna el índice donde se encuentra
        }
    }
    return -1; // -1 significa que no existe
}

// 1. Función para agregar alumno
void AgregarAlumno(vector<Alumno>& grupo) {
    Alumno temp;
    cout << "\n--- Agregar alumno ---\n";
    cout << "Ingresa Matricula:";
    cin >> temp.matricula;

    if (BuscarPorMatricula(grupo, temp.matricula) != -1) {
        cout << "-> Error: La matricula ya existe.\n";
        return;
    }

    cin.ignore(); // Limpiamos el buffer antes del string
    cout << "\nIngresa nombre:";
    getline(cin, temp.alumno);
    cout << "\nIngresa Promedio:";
    cin >> temp.promedio;

    grupo.push_back(temp);
    cout << "\nAlumno agregado correctamente.\n";
}

// 2. Función para mostrar todos
void MostrarAlumnos(const vector<Alumno>& grupo) {
    cout << "\n--- Lista de Alumnos ---\n";
    if (grupo.empty()) {
        cout << "-> No hay alumnos registrados.\n";
        return;
    }
    for (int i = 0; i < grupo.size(); i++) {
        cout << "Matricula: " << grupo[i].matricula
             << " | Nombre: " << grupo[i].alumno
             << " | Promedio: " << grupo[i].promedio << endl;
    }
}

// 3. Función para buscar uno específico
void BuscarAlumno(const vector<Alumno>& grupo) {
    int mat;
    cout << "\nIngresa la matricula a buscar: ";
    cin >> mat;

    int pos = BuscarPorMatricula(grupo, mat);
    if (pos != -1) {
        cout << "-> Encontrado: " << grupo[pos].alumno
             << " (Promedio: " << grupo[pos].promedio << ")\n";
    } else {
        cout << "-> Alumno no encontrado.\n";
    }
}

// 4. Función para actualizar datos
void ActualizarAlumno(vector<Alumno>& grupo) {
    int mat;
    cout << "\nIngresa la matricula del alumno a actualizar: ";
    cin >> mat;

    int pos = BuscarPorMatricula(grupo, mat);
    if (pos != -1) {
        cin.ignore();
        cout << "Nuevo nombre (anterior: " << grupo[pos].alumno << "): ";
        getline(cin, grupo[pos].alumno);
        cout << "Nuevo promedio (anterior: " << grupo[pos].promedio << "): ";
        cin >> grupo[pos].promedio;
        cout << "-> Alumno actualizado correctamente.\n";
    } else {
        cout << "-> Alumno no encontrado.\n";
    }
}

// 5. Función para eliminar
void EliminarAlumno(vector<Alumno>& grupo) {
    int mat;
    cout << "\nIngresa la matricula del alumno a eliminar: ";
    cin >> mat;

    int pos = BuscarPorMatricula(grupo, mat);
    if (pos != -1) {
        grupo.erase(grupo.begin() + pos);
        cout << "-> Alumno eliminado correctamente.\n";
    } else {
        cout << "-> Alumno no encontrado.\n";
    }
}

// 6. Función para ordenar de mayor a menor promedio
void OrdenarDescendente(vector<Alumno>& grupo) {
    if (grupo.empty()) {
        cout << "-> No hay alumnos para ordenar.\n";
        return;
    }
    sort(grupo.begin(), grupo.end(), [](const Alumno& a, const Alumno& b) {
        return a.promedio > b.promedio;
    });
    cout << "-> Grupo ordenado por promedio (Descendente).\n";
}

// 7. Función para ordenar de menor a mayor promedio
void OrdenarAscendente(vector<Alumno>& grupo) {
    if (grupo.empty()) {
        cout << "-> No hay alumnos para ordenar.\n";
        return;
    }
    sort(grupo.begin(), grupo.end(), [](const Alumno& a, const Alumno& b) {
        return a.promedio < b.promedio;
    });
    cout << "-> Grupo ordenado por promedio (Ascendente).\n";
}

// 8. Función para calcular la media
void CalcularPromedioGrupo(const vector<Alumno>& grupo) {
    if (grupo.empty()) {
        cout << "-> No hay alumnos para calcular el promedio.\n";
        return;
    }
    double suma = 0;
    for (int i = 0; i < grupo.size(); i++) {
        suma += grupo[i].promedio;
    }
    cout << "-> El promedio general del grupo es: " << (suma / grupo.size()) << endl;
}

// === FUNCIÓN PRINCIPAL ===
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
        cout << "Selecciona una opcion:";
        cin >> opcion;

        // Aquí está el switch que conecta el menú con las funciones
        switch (opcion) {
            case 1: AgregarAlumno(grupo); break;
            case 2: MostrarAlumnos(grupo); break;
            case 3: BuscarAlumno(grupo); break;
            case 4: ActualizarAlumno(grupo); break;
            case 5: EliminarAlumno(grupo); break;
            case 6: OrdenarDescendente(grupo); break;
            case 7: OrdenarAscendente(grupo); break;
            case 8: CalcularPromedioGrupo(grupo); break;
            case 0: cout << "\nSaliendo del programa...\n"; break;
            default: cout << "\nOpcion no valida. Intente de nuevo.\n"; break;
        }

    } while (opcion != 0);

    return 0;
}
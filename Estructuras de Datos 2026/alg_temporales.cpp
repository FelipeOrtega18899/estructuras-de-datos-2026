#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main () {
    cout << "---Creacion de vectores---" << endl;
    vector<int> v1;

    //vector de tamaño definido
    vector<int> v2[5];

    //vector de tamaño indefinido
    vector<int> v3(5,10);

    //vector con valores iniciales
    vector<int> v4{1,2,3,4,5};

    //imprimir vector
    cout << "Vector ..." << endl;
    for (int x: v3) cout << x << " ";

    //copiar un vector
    vector<int> copia = v4;

    cout << endl << "--------Acceder a elementos de un vector---------" << endl;
    cout << "Acceder a la posicion 2 del vector V4: " << v4[2] << endl;
    cout << "Acceder a la primera posicion del vector V4: " << v4.front() << endl;
    cout << "Acceder a la ultima posicion del vector V4: " << v4.back() << endl;

    cout << "--- Modificar elementos de un vector ---" << endl;
    v4[0] = 100;

    //agregar valor al final
    v4.push_back(50);

    //imprimir un vector (otra vez)
    cout << "Vector ... ";
    for (int x: v4) cout << x << " ";

    //insertar un valor en una posicion especifica
    v4.insert(v4.begin()+2, 99);

    //imprimir un vector (otra vez)
    cout << endl << "Vector ... ";
    for (int x: v4) cout << x << " ";

    //Insertar varios valores
    v4.insert(v4.begin()+1, 3, 10);

    //imprimir un vector (otra vez)
    cout << endl << "Vector ... ";
    for (int x: v4) cout << x << " ";

    //Eliminar una posicion
    v4.erase(v4.begin()+1);

    //imprimir un vector (otra vez)
    cout << endl << "Vector ... ";
    for (int x: v4) cout << x << " ";

    //Eliminar una posicion
    v4.erase(v4.begin()+1, v4.begin() +2);

    //imprimir un vector (otra vez)
    cout << endl << "Vector ... ";
    for (int x: v4) cout << x << " ";

    cout << "---Obtener información del vector---" << endl;
    cout << "Tamanio: " << v4.size() << endl;
    cout << "Capacidad: " << v4.capacity() << endl;

    //validar si está vacío o no
    cout << "Esta vacio? " << (v4.empty() ? "Si" : "No") << endl;

    //modificaciones de capacidades
    cout << "--- Control de capacidades ---" << endl;
    v4.reserve(100);

    cout << "Capacidad v4: " << v4.capacity() << endl;
    v4.resize(20,5);

    //imprimir un vector (otra vez)
    cout << endl << "Vector ... ";
    for (int x: v4) cout << x << " ";

    v4.reserve(v4.capacity());

    //recorrer vectores
    for (int i = 0; i < v4.size(); i++) {
        cout << v4[i] << " ";
    }
    //recorrer con for each
    for (int x: v4) cout << x << " ";

    cout << "--- Algoritmos ---" << endl;
    vector <int> datos = {9,3,5,10,8,4};

    //ordenar
    sort(datos.begin(), datos.end());

    cout << "Vector ordenado: " << endl;
    for (int x: datos) cout << x << " ";
    cout << endl;

    cout << "Valor maximo: " << *max_element(datos.begin(),datos.end()) << endl;
    cout << "Valor minimo: " << *min_element(datos.begin(),datos.end()) << endl;

    //invertir un vector
    reverse(datos.begin(), datos.end());
}

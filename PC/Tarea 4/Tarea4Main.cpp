#include "Tarea4.h"
#include <iostream>

using namespace std;

int main() {

    int arreglo[] = {1,2,3,4,5,6,7,8,9};
    int n;
    cout << "Ingresar valor a buscar de forma iterativa: ";
    cin >> n;

    int i = Busqueda_Binaria_Iterativa(n, arreglo, 8);
    if (i != -1) {
        cout << "El indice del numero " << n << " es: " << i << endl;
    } else {
        cout << "El numero no se encuentra en el arreglo" << endl;
    }

    cout << "Ingresar valor a buscar de forma recursiva: ";
    cin >> n;
    i = Busqueda_Binaria_Iterativa(n, arreglo, 8);
    if (i != -1) {
        cout << "El indice del numero " << n << " es: " << i << endl;
    } else {
        cout << "El numero no se encuentra en el arreglo" << endl;
    }

    cout << "Ingresar cantidad de discos para la Torre de Hanoi: ";
    cin >> n;

    Torre_De_Hanoi(n, '1', '2', '3');

}
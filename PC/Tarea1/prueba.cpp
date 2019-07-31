#include "orden.h"
#include <stdio.h>
#include <iostream>

using namespace std;

void imprimirMenu();
void imprimirArreglo(int size, int arreglo[]);

int main() {
	int arreglo[] = {1, 2, 3, 4, 5};
	int arreglo2[] = {3, 2, 5, 6, 1, 4, 9, 7, 8, 10};
	cout << "Tarea 1, Elaborado Por: Sebastian Molano" << endl;
	
	int input;
	bool funcionando = true;
	while (funcionando) {
		imprimirMenu();
		cin >> input;
		switch(input) {
			case 1:
				cout << "Arreglo actual: ";
				imprimirArreglo(5, arreglo);
				cout << endl;
				cout << "Arreglo ordenado: ";
				ordenar(5, arreglo, true);
				imprimirArreglo(5, arreglo);
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
			default:
				cout << "Entrada invalida.";
				cout << endl;
				break;
		}
	}
	
	return 1;
	
}

void imprimirMenu() {
	cout << endl;
	cout << "Requerimientos: " << endl;
	cout << "1. Ordenar por burbuja (Ascendente)" << endl;
	cout << "2. Ordenar por burbuja (Descendente)" << endl;
	cout << "3. Busqueda lineal" << endl;
	cout << "4. Busqueda binaria" << endl;
	cout << "5. Generar n numeros aleatorios no repetidos" << endl;
	cout << endl;
	cout << "Introducir numero: ";
}

void imprimirArreglo(int size, int arreglo[]) {
	for(int i = 0; i < size; i++) {
		cout << arreglo[i] << " ";
	}
	cout << endl;
}


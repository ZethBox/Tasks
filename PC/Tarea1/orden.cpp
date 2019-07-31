/*
* Elaborado por: Sebastián Molano en Dev-C++ v5.11
*/

#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "orden.h"
using namespace std;

/**
* Genera un número aleatorio en un rango dado
* Entradas:
*	rango: rango del cual se genera un numero aleatorio (de 0 - rango)
* Salidas:
*	retorna un numero aleatoria entre 0 y el rango
*/
int generarAleatorio(int rango);

/**
* Identifica la cantidad de numeros no repetidos de un arreglo 
* Entradas:
* 	arreglo: arreglo del cual se quieren identificar los no repetidos
*	repetidos: apuntador a un arreglo preferiblemente vacio donde se guardan los valores unicos del arreglo original
* Salidas:
*	numero de elementos no repetidos contenidos en el arreglo
*/
int numerosNoRepetidos(int size, int arreglo[], int* repetidos);

/**
* Identifica si el arreglo contiene cierto elemento
* Entradas:
*	size: longitud del arreglo
*	arreglo: arreglo a buscar
*	buscado: Elemento buscado
* Salidas:
*	Retorna true si el elemento se encuentra en el arreglo, false de lo contrario
*/
bool contains(int size, int arreglo[], int buscado);

void ordenar(int size, int arreglo[], bool ascendente) {
	for(int i = 0; i < size; i++) {
		for(int j = i + 1; j < size; j++) {
			if (ascendente) {
				if(arreglo[i] > arreglo[j]) {
					int temp = arreglo[i];
					arreglo[i] = arreglo[j];
					arreglo[j] = temp;
				}
			} 
			else {
				if(arreglo[i] < arreglo[j]) {
					int temp = arreglo[i];
					arreglo[i] = arreglo[j];
					arreglo[j] = temp;
				}
			}
		}
	}
}

int busquedaLineal(int size, int arreglo[], int buscado) {
	for(int i = 0; i < size; i++) {
		if(arreglo[i] == buscado) {
			return arreglo[i];
		}
	}
	return -1;
}

int busquedaBinaria(int size, int arreglo[], int buscado) {
	int alto = size - 1;
	int bajo = 0;
	int medio;
	
	while(bajo <= alto) {
		
		medio = (alto + bajo) / 2;
		if(arreglo[medio] < buscado) {
			bajo = medio + 1;
		}
		else if(arreglo[medio] > buscado) {
			alto = medio - 1;
		}
		else {
			return arreglo[medio];
		}
	}
	return -1;
}

char* darAleatorios(int size, int arreglo[], int n) {
	//Arreglo de no repetidos
	int* NoRepetidos = new int[size];
	int* repetidos = new int[size];
	
	char* retorno; 
		
	int aleatorio;
	//Longitud del arreglo de no repetidos
	int repTam = numerosNoRepetidos(size, arreglo, NoRepetidos); 
	//Si n es menor a la longitud del arreglo y hay igual o mayor cantidad de no repetidos que n
	if (n <= size && n <= repTam) {
		for(int i = 0; i < n; i++) {
			aleatorio = generarAleatorio(repTam);
			//Si el elemento aleatorio ya esta en el arreglo, se genera un nuevo elemento aleatorio y se repite la iteracion
			if(contains(repTam, repetidos, NoRepetidos[aleatorio])) {
				i--;
			}
			else {
				repetidos[i] = NoRepetidos[aleatorio];
			}
		}
		return reinterpret_cast<char*>(repetidos);
	}
	else {
		cout << "No hay suficientes numeros no repetidos en el arreglo para generar " << n << " numeros aleatorios. Numeros no repetidos: " << repTam << endl;
		return (char *)"";
	}	
}

int numerosNoRepetidos(int size, int arreglo[], int* repetidos) {
	int total = 0;
	int j = 0;
	for(int i = 0; i < size; i++) {
		if(!contains(size, repetidos, arreglo[i])) {
			repetidos[j] = arreglo[i];
			total++;
			j++;
		}
	}
	cout << "\n";
	return total;
}

bool contains(int size, int arreglo[], int buscado) {
	for(int i = 0; i < size; i++) {
		if(arreglo[i] == buscado) {
			return true;
		}
	}
	return false;
}

int generarAleatorio(int rango) {
	return rand() % (rango + 1);
}

void imprimirArreglo(int size, int arreglo[]) {
	for(int i = 0; i < size; i++) {
		cout << arreglo[i] << " ";
	}
	cout << endl;
}

//Pruebas de las funciones privadas.
int main() {
	srand(time(NULL));
	
	int arreglo[] = {5, 5, 4, 2, 3};
	int rep[] = {0, 0, 0, 0, 0};
	cout << "Arreglo: ";
	imprimirArreglo(5, arreglo);
	
	ordenar(5, arreglo, true);
	cout << "Arreglo ordenado: ";
	imprimirArreglo(5, arreglo);
	
	ordenar(5, arreglo, false);
	cout << "Arreglo ordenado de forma descendente: ";
	imprimirArreglo(5, arreglo);
	
	char* string;
	int response;
	int input;
	bool in = true;
	while(in) {
		cout << "Tareas" << endl;
		cout << "1. Generar aleatorio" << endl;
		cout << "2. Numero de numeros no repetidos del arreglo" << endl;
		cout << "3. Contiene un elemento" << endl;
		cin >> response;
		switch(response) {
			case 1:
				cout << "Ingresar valor del rango" << endl;
				cin >> input;
				cout << "Numero aleatorio = " << generarAleatorio(input) << endl;
				break;
			case 2:
				cout << "Cantidad de numeros no repetidos del arreglo: " << numerosNoRepetidos(5, arreglo, rep);
				break;
			case 3:
				cout << "Ingresar numero a buscar: " << endl;
				cin >> input;
				if(contains(5, arreglo, input)) {
					cout << "El elemento " << input << ", esta contenido en el arreglo" << endl;
				}
				else {
					cout << "El elemento no esta contenido en el arreglo" << endl;
				}
				break;
			case 4:
				
				break;
			default:
				cout << "Entrada invalida" << endl;
				break;
		}
		cout << endl;
	}
	
	getchar();
}

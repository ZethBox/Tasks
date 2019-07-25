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
*/
int generarAleatorio(int rango);

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

int darAleatorios(int size, int arreglo[], int n) {
	for(int i = 0; i < n; i++) {
		cout << generarAleatorio(size) << endl;
		
	}
	return 0;
}

int generarAleatorio(int rango) {
	return rand() % rango;
}

int main() {
	srand(time(NULL));
	
	int arreglo[] = {3, 2, 4, 5, 1};
	ordenar(5, arreglo, true);
	
	for(int i = 0; i < 5; i++) {
		cout << arreglo[i] << " " << endl;
	}
	
	cout << busquedaLineal(5, arreglo, 6) << endl;
	
	for(int i = 0; i < 8; i++) {
		cout << busquedaBinaria(5, arreglo, i+1) << endl;
	}
	
	getchar();
}

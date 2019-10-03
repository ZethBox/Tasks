#include "orden.h"
#include <iostream>

using namespace std;

void imprimirMenu();
void imprimirArr(int size, int *arreglo);

int main() {
	int arreglo[] = {1, 2, 3, 4, 5};
	int arreglo2[] = {3, 2, 5, 6, 1, 4, 9, 7, 8, 10};
	cout << "Tarea 1, Elaborado Por: Sebastian Molano" << endl;
	
	int input;
	int in;
	bool funcionando = true;
	while (funcionando) {
		imprimirMenu();
    
		cin >> input;
		switch(input) {
			case 1:
				cout << "Arreglo actual: ";
				imprimirArr(10, arreglo2);
				cout << endl;
				cout << "Arreglo ordenado: ";
				ordenar(10, arreglo2, true);
				imprimirArr(10, arreglo2);
				break;
			case 2:
        cout << "Arreglo actual: ";
				imprimirArr(10, arreglo2);
				cout << endl;
				cout << "Arreglo ordenado: ";
				ordenar(10, arreglo2, false);
				imprimirArr(10, arreglo2);
				break;
			case 3:
			  cout << "Introducir numero buscado: " << endl;
			  cin >> in;
			  cout << "Numero: " << in << endl;
			  if(busquedaLineal(10, arreglo2, in) != -1) {
			    cout << "El numero buscado se encuentra en el arreglo" << endl;
			  }
			  else {
			    cout << "El numero buscado no se encuentra en el arreglo" << endl;
			  }
				break;
			case 4:
			  cout << "Introducir n�mero buscado: " << endl;
			  cin >> in;
			  cout << "N�mero " << in << endl;
			  if(busquedaBinaria(10, arreglo2, in) != -1) {
			    cout << "El numero buscado se encuentra en el arreglo" << endl;
			  }
			  else {
			    cout << "El n�mero buscado no se encuentra en el arreglo" << endl;
			  }
				break;
			case 5:
			  cout << "Ingresar la cantidad de numeros aleatorios a generar: ";
			  cin >> in;
			  cout << "n = " << in << endl;
			  cout << darAleatorios(10, arreglo2, in) << endl;
				break;
			case 6: 
			  cout << "Ingresar la cantidad de numeros aleatorios a generar: ";
        cin >> in;
        cout << "n = " << in << endl;
        cout << generarAleatorios(in) << endl;
        break;
      case 7:
        funcionando = false;
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
	cout << "5. Generar n numeros aleatorios no repetidos desde el arreglo" << endl;
	cout << "6. Generar n numeros aleatorios no repetidos" << endl;
	cout << "7. Dejar de ejecutar." << endl;
	cout << endl;
	cout << "Introducir numero: ";
}

void imprimirArr(int size, int *arreglo) {
	for(int i = 0; i < size; i++) {
		cout << *(arreglo + i) << " ";
	}
	cout << endl;
}


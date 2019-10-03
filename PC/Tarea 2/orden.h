/*
* Elaborado por: Sebasti�n Molano 
* El codigo no parece funcionar en algunos compiladores de dev-c++ falla al importar
* <string> y falla al referenciar la libreria.
*/

#ifndef ORDEN_H_
#define ORDEN_H_
#include <stdbool.h> 
#include <string>
/**
* Ordena un arreglo en orden ascendente o descendente
* Entradas:
* 	size: tama�o del arreglo
* 	arreglo: arreglo a ser ordenado
* 	ascendente: indica si el ordenamiento se realiza en orden ascendente o descendiente
*/
void ordenar(int size, int *arreglo, bool ascendente);

/**
* Busca un entero en un arreglo de forma lineal
* Entradas:
*	size: tama�o del arreglo
* 	arreglo: arreglo donde buscar
*	buscado: elemento a buscar
* Salidas:
*	retorna el elemento buscado o -1 si no est� en el arreglo
*/
int busquedaLineal(int size, int *arreglo, int buscado);

/**
* Busca un entero en un arreglo por el algoritmo de b�squeda binaria
* Entradas:
*	size: tama�o del arreglo
* 	arreglo: arreglo donde buscar
*	buscado: elemento a buscar
* Salidas:
*	retorna el elemento buscado o null si no est� en el arreglo
*/
int busquedaBinaria(int size, int *arreglo, int buscado);

/**
* Retorna una cadena con n n�meros aleatorios sin repeticion tomados de un arreglo. Ya que los numeros aleatorios generados 
* no pueden ser repetidos, el arreglo debe tener n o mas numeros no repetidos para que funcione.
* Entradas:
*	size: tama�o del arreglo
* 	arreglo: arreglo de donde se toman los n�meros
*	n: cantidad de n�meros a tomar del arreglo
* Salidas:
*	retorna una cadena con n elementos aleatorios sacados del arreglo original.
*	si n es mayor a la cantidad de elementos del arreglo o si no hay suficientes numeros no repetidos en el arreglo, la
* 	funcion retorna NULL.
*/
std::string darAleatorios(int size, int *arreglo, int n);

/**
* Genera n numeros en orden aleatorio no repetidos de 0 a n
* Entradas:
*   n: cantidad de numeros aleatorios a generar
* Salidas:
*   cadena con los numeros aleatorios generados
*/
std::string generarAleatorios(int n);

#endif

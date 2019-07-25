/*
* Elaborado por: Sebastián Molano
*/

#ifndef ORDEN_H_
#define ORDEN_H_

/**
* Ordena un arreglo en orden ascendente o descendente
* Entradas:
* 	size: tamaño del arreglo
* 	arreglo: arreglo a ser ordenado
* 	ascendente: indica si el ordenamiento se realiza en orden ascendente o descendiente
*/
void ordenar(int size, int arreglo[], bool ascendente);

/**
* Busca un entero en un arreglo de forma lineal
* Entradas:
*	size: tamaño del arreglo
* 	arreglo: arreglo donde buscar
*	buscado: elemento a buscar
* Salidas:
*	retorna el elemento buscado o -1 si no está en el arreglo
*/
int busquedaLineal(int size, int arreglo[], int buscado);

/**
* Busca un entero en un arreglo por el algoritmo de búsqueda binaria
* Entradas:
*	size: tamaño del arreglo
* 	arreglo: arreglo donde buscar
*	buscado: elemento a buscar
* Salidas:
*	retorna el elemento buscado o null si no está en el arreglo
*/
int busquedaBinaria(int size, int arreglo[], int buscado);

/**
* Retorna un arreglo de n números aleatorios tomados de un arreglo. Los números aleatorios no son repetidos
* Entradas:
*	size: tamaño del arreglo
* 	arreglo: arreglo de donde se toman los números
*	n: cantidad de números a tomar del arreglo
* Salidas:
*	retorna un arreglo con n elementos aleatorios sacados del arreglo original
*/
int darAleatorios(int size, int arreglo[], int n);

#endif

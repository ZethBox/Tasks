/*
* Elaborado por: Sebasti�n Molano
*/

#ifndef ORDEN_H_
#define ORDEN_H_
#include <stdbool.h> 
#include <stdio.h>
#include "string.h"

/**
* Ordena un arreglo en orden ascendente o descendente
* Entradas:
* 	size: tama�o del arreglo
* 	arreglo: arreglo a ser ordenado
* 	ascendente: indica si el ordenamiento se realiza en orden ascendente o descendiente
*/
void ordenar(int size, int arreglo[], bool ascendente);

/**
* Busca un entero en un arreglo de forma lineal
* Entradas:
*	size: tama�o del arreglo
* 	arreglo: arreglo donde buscar
*	buscado: elemento a buscar
* Salidas:
*	retorna el elemento buscado o -1 si no est� en el arreglo
*/
int busquedaLineal(int size, int arreglo[], int buscado);

/**
* Busca un entero en un arreglo por el algoritmo de b�squeda binaria
* Entradas:
*	size: tama�o del arreglo
* 	arreglo: arreglo donde buscar
*	buscado: elemento a buscar
* Salidas:
*	retorna el elemento buscado o null si no est� en el arreglo
*/
int busquedaBinaria(int size, int arreglo[], int buscado);

/**
* Retorna un arreglo de n n�meros aleatorios tomados de un arreglo. Los n�meros aleatorios no son repetidos por lo que se requiere
* un arreglo sin numeros repetidos como entrada para garantizar el funcionamiento adecuado del metodo
* Entradas:
*	size: tama�o del arreglo
* 	arreglo: arreglo de donde se toman los n�meros
*	n: cantidad de n�meros a tomar del arreglo
* Salidas:
*	retorna una cadena con n elementos aleatorios sacados del arreglo original
*/
char* darAleatorios(int size, int arreglo[], int n);

#endif

/**
 * Realizado por: Sebastian Molano
 */
#pragma once

/**
 * Realiza una busqueda binaria utilizando iteraciones
 * Entradas:
 *  buscado - Elemento buscado
 *  arreglo - arreglo donde se realiza la busqueda
 *  size - longitud del arreglo
 * Salidas:
 *  Retorna el indice del elemento buscado o -1 si no lo encuentra
 */
template<class T>
int Busqueda_Binaria_Iterativa(T buscado, T arreglo[], int size);

/**
 * Realiza una busqueda binaria utilizando recursividad
 * Entradas:
 *  buscado - Elemento buscado
 *  arr - arreglo donde se ejecutan las operaciones
 *  l - limite inferior del arreglo
 *  h - limite superior del arreglo
 * Salidas:
 *  Retorna el indice del elemento buscado o -1 si no lo encuentra
 */
template<class T>
int Busqueda_Binaria_Recursiva(int buscado, T arr[], int l, int h);

/**
 * Realiza el algoritmo recursivo para resolver las torres de hanoi
 * Entradas:
 *  n - cantidad de discos en la torre
 *  origen - la torre de origen
 *  aux - la torre auxiliar
 *  destino - la torre destino
 */ 
void Torre_De_Hanoi(int n, char origen, char aux, char destino);
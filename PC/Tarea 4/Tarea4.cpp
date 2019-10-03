#include <iostream>
using namespace std;

template <class T>
T Busqueda_Binaria_Iterativa(T buscado, T arreglo[], int size)
{
    if (buscado > arreglo[size - 1] || buscado < arreglo[0])
    {
        return -1;
    }
    int l, h, m;
    l = 0;
    h = size - 1;
    m = (h + l) / 2;
    while (h > l)
    {
        if (buscado > arreglo[m])
        {
            l = m + 1;
        }
        else if (buscado < arreglo[m])
        {
            h = m;
        }
        else
        {
            return m;
        }
        m = (h + l) / 2;
    }
    return -1;
}

template <class T>
T busqueda_lineal_recursiva(int buscado, T arr[], int l, int h) {
  int m = (l+h) / 2;
  if(l > h) {
    return -1;
  }
  if(buscado == arr[m]) {
    return m;
  }
  else if(l == h) {
    return -1;
  } 
  else if(buscado > arr[m]) {
    return busqueda_lineal_recursiva(buscado, arr, m+1, h);
  }
  else {
    return busqueda_lineal_recursiva(buscado, arr, l, m);
  }
}

void Torre_De_Hanoi(int n, char origen, char destino, char auxiliar) {
    if(n == 1) {
        return;
        //Para cuando la torre del origen solo tiene un disco pues solo le queda mover ese a la torre destino
        cout << "Mover el ultimo disco de la torre origen a la torre destino";
    }
    Torre_De_Hanoi(n-1, origen, auxiliar, destino);
    cout << "Mover el disco " << n-1 << " a la torre: " << auxiliar;
    Torre_De_Hanoi(n-1, auxiliar, destino, origen);
    cout << "Mover el disco " << n-1 << " a la torre: " << destino;
}
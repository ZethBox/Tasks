#include <iostream>
#include <string>
using namespace std;

/**
 * Inicializa las letras del diccionario de la A a la Z. 
 * Entradas:
 *  ABC: diccionario donde se guardan las letras
 */
void inicializarLetras(struct Letra *ABC);

/**
 * Busca una palabra en el diccionario, retorna true si la palabra se encuentra en el 
 * diccionario, false si la palabra no se encuentra en el.
 */
bool buscarPalabra(struct Letra *ABC, string palabra);

/**
 * Crea un dialogo preguntando si colocar una nueva palabra en el diciconario.
 * Si el usuario acepta, se llama a la funcion de insertar palabra
 */
bool preguntarInsertar(struct Letra *ABC, string palabra);

/**
 * Inserta una palabra en el diccionario pasado como parametro
 * Entradas:
 *  ABC: diccionario donde se va a insertar la palabra
 *  palabra: palabra que se va a insertar en el diccionario
 *  buscar: indica si se quiere buscar en el diccionario primero antes de agregar la palabra
 *      si no, se asume que la palabra no esta en el diccionario.
 */
void insertarPalabra(struct Letra *ABC, string palabra, bool buscar);

/**
 * Imprime un diccionario en consola
 */
void imprimirDiccionario(struct Letra *ABC);

/**
 * El struct de letra representa una letra del diccionario. A cada letra hay asociada la letra
 * en si, un numero que representa la cantidad de palabras que tiene y un arreglo de strings 
 * que representa las palabras que tiene.
 */
struct Letra
{
    int noPalabras;
    char letra;
    string *palabras;
};

void imprimirDiccionario(struct Letra *ABC)
{
    struct Letra *letra;
    string *palabras;
    for (int i = 0; i < 27; i++)
    {
        letra = (ABC + i);
        cout << letra->letra << ": ";
        palabras = ABC->palabras;
        for (int j = 0; j < letra->noPalabras; j++)
        {
            cout << palabras++ << " ";
        }
        cout << endl;
    }
}

void inicializarLetras(struct Letra *ABC)
{
    struct Letra *dic = ABC;
    for (int i = 0; i < 26; i++)
    {
        if (i != 14)
        {
            dic->letra = 'A' + i;
        }
        else
        {
            dic->letra = 'Ñ';
            dic->noPalabras = 0;
            dic->palabras = NULL;
            dic++;
            dic->letra = 'O';
        }
        dic->noPalabras = 0;
        dic->palabras = NULL;
        dic++;
    }
}

bool buscarPalabra(struct Letra *ABC, string palabra)
{
    Letra *p = ABC;

    char primeraLetra = palabra.at(0);
    bool encontro = false;

    for (int i = 0; i < 27 && !encontro; i++)
    {
        if (p->letra == primeraLetra)
        {
            encontro = true;
        }
        else
        {
            p++;
        }
    }
    if (encontro)
    {
        string *q = p->palabras;
        int numPalabras = p->noPalabras;

        for (int i = 0; i < numPalabras; i++)
        {
            if (palabra == *q)
            {
                return true;
            }
            q++;
        }
        insertarPalabra(p, palabra, false);
        
    }
    else
    {
        return false;
    }
}

bool preguntarInsertar(struct Letra *ABC, string palabra)
{
    cout << "La palabra '" << palabra << "' No se encuentra en el diccionario, desea insertarla?" << endl;
    cout << "1. Si" << endl;
    cout << "2. No" << endl;
    int input;
    cin >> input;

    switch (input)
    {
    case 1:
        cout << "La palabra sera insertada" << endl;
        return true;
        break;
    case 2:
        cout << "La palabra no sera insertada" << endl;
        return false;
        break;
    default:
        cout << "Entrada invalida..." << endl;
        return false;
    }
}

void insertarPalabra(struct Letra *ABC, string palabra, bool buscar)
{
    int nPalabras = ABC->noPalabras;
    string *palabras = ABC->palabras;
    for(int i  = 0; i < nPalabras; i++) {
        cout << palabras++;
    }
}

int main()
{
    Letra *diccionario = new Letra[27];
    inicializarLetras(diccionario);
    imprimirDiccionario(diccionario);
    buscarPalabra(diccionario, "Hola");
    delete (diccionario);
}

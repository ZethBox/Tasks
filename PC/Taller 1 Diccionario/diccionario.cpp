#include <iostream>
#include <string>
#include <algorithm>
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
 * Inserta una palabra en el diccionario pasado como parametro
 * Entradas:
 *  ABC: diccionario donde se va a insertar la palabra
 *  palabra: palabra que se va a insertar en el diccionario
 *  buscar: indica si se quiere buscar en el diccionario primero antes de agregar la palabra
 *      si no, se asume que la palabra no esta en el diccionario.
 */
void insertarPalabra(struct Letra *ABC, string pal);

/**
 * Imprime un diccionario en consola
 */
void imprimirDiccionario(struct Letra *ABC);

/**
* Transforma una palabra para ser compatible con el diccionario
*/
string transformar(string palabra);

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
        palabras = letra->palabras;
        for (int j = 0; j < letra->noPalabras; j++)
        {
            cout << palabras[j] << " ";
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

    char letraActual = palabra.at(0);
    bool encontro = false;

    for (int i = 0; i < 27 && !encontro; i++)
    {
        if (p->letra == letraActual)
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
        return true;
    }
    else
    {
        return false;
    }
}

void insertarPalabra(struct Letra *ABC, string pal)
{
    string palabra = transformar(pal);
    Letra *dic = ABC;
    char letraActual = palabra.at(0);
    bool encontro = false;
    for (int i = 0; i < 27 && !encontro; i++)
    {
        if (dic->letra == letraActual)
        {
            encontro = true;
        }
        else
        {
            dic++;
        }
    }
    if (encontro)
    {
        if (dic->noPalabras == 0)
        {
            dic->palabras = new string[++dic->noPalabras];
            *(dic->palabras + 0) = palabra;
        }
        else
        {
            int nP = dic->noPalabras;
            string *palabras = new string[++dic->noPalabras];
            for (int i = 0; i < nP; i++)
            {
                *(palabras + i) = *(dic->palabras + i);
            }
            *(palabras + nP) = palabra;
            delete (dic->palabras);
            dic->palabras = palabras;
        }
    }
}

string transformar(string palabra)
{
    string pal = palabra;
    transform(pal.begin(), pal.end(), pal.begin(), ::toupper);
    char letraActual;
    for (int i = 0; i < pal.size(); i++)
    {
        letraActual = pal.at(i);
        if (letraActual == 'Á' || letraActual == 'á')
        {
            letraActual = 'A';
        }
        else if (letraActual == 'É' || letraActual == 'é')
        {
            letraActual = 'E';
        }
        else if (letraActual == 'Í' || letraActual == 'í')
        {
            letraActual = 'I';
        }
        else if (letraActual == 'Ó' || letraActual == 'ó')
        {
            letraActual = 'O';
        }
        else if (letraActual == 'Ú' || letraActual == 'ú')
        {
            letraActual = 'U';
        }
        pal.at(i) = letraActual;
    }
    return pal;
}

int main()
{
    Letra *diccionario = new Letra[27];
    inicializarLetras(diccionario);
    insertarPalabra(diccionario, "Ala");
    insertarPalabra(diccionario, "Bota");
    insertarPalabra(diccionario, "Capa");
    insertarPalabra(diccionario, "Delta");
    insertarPalabra(diccionario, "Celta");
    insertarPalabra(diccionario, "Pisques");
    insertarPalabra(diccionario, "Bárbaro");
    insertarPalabra(diccionario, "ñero");
    insertarPalabra(diccionario, "oráculo");
    insertarPalabra(diccionario, "Elefanto");
    insertarPalabra(diccionario, "Fuerza");
    insertarPalabra(diccionario, "Gatillo");
    insertarPalabra(diccionario, "Hera");

    if(buscarPalabra(diccionario, "HERA")) {
        cout << "La palabra HERA se encuentra en el diccionario" << endl;
    }

    imprimirDiccionario(diccionario);
    
    for(int i = 0; i < 27; i++) {
        delete(diccionario->palabras);
        diccionario++;
    }
    delete (diccionario);

}

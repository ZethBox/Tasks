//Realizado por Sebastian Molano y Andres Gonzalez
#include <iostream>
#include "string.h"
using namespace std;

struct Token {
    char* palabra;
    int repeticiones;
};

void ordenar(Token* arreglo, int size) {
	int i,j;
	Token temp;
	for(i = 0; i < size; i++) {
		for(j = 0; j < size-i-1; j++) {
			if(arreglo[j].repeticiones < arreglo[j + 1].repeticiones) {
				temp = arreglo[j];
				arreglo[j] = arreglo[j + 1];
				arreglo[j + 1] = temp;
			}
		}
	}
}

bool amin(char* pal1, char* pal2) {
	if(strlen(pal1) != strlen(pal2)) 
		return false;
	for(int i = 0; i < strlen(pal1); i++) {
		pal1[i] = tolower(pal1[i]);
		pal2[i] = tolower(pal2[i]);
	}
	if(strcmp(pal1, pal2) != 0) 
		return false;
	return true;
}

bool enArreglo(char* palabra, Token* arreglo, int size) {
    for(int i = 0; i < size; i++) {
        if(amin(arreglo[i].palabra, palabra)) {
            ++arreglo[i].repeticiones;
            return true;
        }
    }
    return false;
}

void agregarToken(Token*& arreglo, int size, char* palabra) {
    Token* temp = new Token[size + 1];
    for(int i = 0; i < size; i++) {
        temp[i] = arreglo[i];
    }
    Token tok;
    tok.palabra = palabra;
    tok.repeticiones = 1;
    temp[size] = tok;
    delete[] arreglo;
    arreglo = temp;
 }

Token* darArregloTokens(char* cadena, int &size) {
    //Longitud del arreglo
    Token* tokens = new Token[++size];
    Token tok;
    char* token = strtok(cadena, " ");
    tok.palabra = token;
    tok.repeticiones = 1;
    tokens[0] = tok;
    token = strtok(NULL, " ");

    while(token != NULL) {
        if(!enArreglo(token, tokens, size)) {
            agregarToken(tokens, size, token);
            size++;
        }
        token = strtok(NULL, " ");
    }
    return tokens;
}


int main() {
    char str[200];
    cin.getline(str, 200);
    int size = 0;
    Token *tokens = darArregloTokens(str, size);
    ordenar(tokens, size);
    for(int i = 0; i < size; i++) {
        cout << tokens[i].palabra << " : " << tokens[i].repeticiones << endl;
    }
    cout << size;
}


#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <fstream>
#include <cstdlib>
#include <chrono>
#include "source.h"
using namespace std;
#define ya chrono::high_resolution_clock::now




void decreciente() {
  vector<int> elementos;
  vector<bool> validar;
  stack<int> pila;
  elementos.push_back(1);
  elementos.push_back(2);
  elementos.push_back(3);
  elementos.push_back(4);
  elementos.push_back(5);
  elementos.push_back(6);
  elementos.push_back(7);

  for (int i = 0; i < 7; i++) {
      validar.push_back(true);
    }
  int inicio = 0;
  int fin = elementos.size()-1;
  SecuDecreciente(elementos,validar,pila,inicio,fin);
  while (pila.size() != 0) {
    cout << elementos[pila.top()]<< endl;;
    validar[pila.top()] = true;
    pila.pop();
    }
}
void creciente() {
  vector<int> elementos;
  vector<bool> validar;
  stack<int> pila;
  elementos.push_back(1);
  elementos.push_back(2);
  elementos.push_back(3);
  elementos.push_back(4);
  elementos.push_back(5);
  elementos.push_back(6);
  elementos.push_back(7);

  for (int i = 0; i < 7; i++) {
      validar.push_back(true);
    }
  int inicio = 0;
  int fin = elementos.size()-1;
  SecuCreciente(elementos,validar,pila,inicio,fin);
  while (pila.size() != 0) {
    cout << elementos[pila.top()]<< endl;;
    validar[pila.top()] = true;
    pila.pop();
    }
}
void test_1() {
  vector<int> elementos;
  vector<bool> validar;
  stack<int> pila;
  elementos.push_back(2);
  elementos.push_back(31);
  elementos.push_back(7);
  elementos.push_back(12);
  elementos.push_back(16);
  for (int i = 0; i < 5; i++) {
      validar.push_back(true);
    }
  int  inicio = elementos.size()-1;
  azules(elementos,validar,pila,inicio,0);
  while (pila.size() != 0) {
    cout << elementos[pila.top()]<< endl;
    pila.pop();
  }
}
void test_2() {
  vector<int> elementos;
  vector<bool> validar;
  stack<int> pila;
  elementos.push_back(3);
  elementos.push_back(11);
  elementos.push_back(0);
  elementos.push_back(1);
  elementos.push_back(3);
  elementos.push_back(5);
  elementos.push_back(2);
  elementos.push_back(4);
  elementos.push_back(1);
  elementos.push_back(0);
  elementos.push_back(9);
  elementos.push_back(3);
  for (int i = 0; i < 12; i++) {
      validar.push_back(true);
    }
  int inicio = 0;
  int fin = elementos.size()-1;
  rojos(elementos,validar,pila,inicio,fin);
  //std::cout << "pila size" << pila.size() <<std::endl;
  while (pila.size() != 0) {
    cout << elementos[pila.top()]<< endl;
    pila.pop();
  }
}



void test_3() {
  vector<int> elementos;
  vector<bool> validar;
  stack<int> pila;
  elementos.push_back(1);
  elementos.push_back(2);
  elementos.push_back(3);
  elementos.push_back(4);
  elementos.push_back(5);
  elementos.push_back(6);
  elementos.push_back(7);
  elementos.push_back(7);
  elementos.push_back(6);
  elementos.push_back(5);
  elementos.push_back(4);
  elementos.push_back(3);
  elementos.push_back(2);
  elementos.push_back(1);

  for (int i = 0; i < 14; i++) {
      validar.push_back(true);
    }
  int fin = elementos.size()-1;
  azules(elementos,validar,pila,0,fin);
  while (pila.size() != 0) {
    cout << elementos[pila.top()]<< endl;
    pila.pop();
  }
}

void backtracking() {
  vector<int> elementos;
  vector<bool> validar;
  elementos.push_back(1);
  elementos.push_back(2);
  elementos.push_back(3);
  elementos.push_back(4);
  elementos.push_back(5);
  elementos.push_back(6);
  elementos.push_back(7);
  elementos.push_back(1);
  elementos.push_back(2);
  elementos.push_back(3);
  elementos.push_back(4);
  elementos.push_back(5);
  elementos.push_back(6);
  elementos.push_back(7);
  for (int i = 0; i < 14; i++) {
      validar.push_back(true);
    }
  int libres = CantidadPosicionesOcupadas(elementos,validar);
  cout << "los libres son "<< libres << endl;
}
void backtracking_2() {
  vector<int> elementos;
  vector<bool> validar;
  elementos.push_back(0);
  elementos.push_back(7);
  elementos.push_back(1);
  elementos.push_back(2);
  elementos.push_back(2);
  elementos.push_back(1);
  elementos.push_back(5);
  elementos.push_back(0);

  for (int i = 0; i < 7; i++) {
      validar.push_back(true);
    }
  int libres = CantidadPosicionesOcupadas(elementos,validar);
  cout << "los libres son "<< libres << endl;
}
void backtracking_3() {
  vector<int> elementos;
  vector<bool> validar;
  elementos.push_back(0);
  elementos.push_back(8);
  elementos.push_back(4);
  elementos.push_back(12);
  elementos.push_back(2);
  elementos.push_back(10);
  elementos.push_back(6);
  elementos.push_back(14);
  elementos.push_back(1);
  elementos.push_back(9);
  elementos.push_back(5);
  elementos.push_back(13);
  elementos.push_back(3);
  elementos.push_back(11);

  for (int i = 0; i < elementos.size(); i++) {
      validar.push_back(true);
    }
  int libres = CantidadPosicionesOcupadas(elementos,validar);
  cout << "los libres son "<< libres << endl;
}


void test_random() {
  ofstream archivo ("resultados_random_ej1.txt");
  vector<int> elementos;
  vector<bool> validar;
  int saltos = 2;
  int rango = 26;
  int repeticiones = 10;
  archivo << rango <<"\n";
  for (int i = 0; i < rango; i++) {
    int tamanio = saltos*(i+1);
    archivo  << tamanio<< " \n" ;
      for (int j = elementos.size(); j < tamanio; j++) {
        int valor = rand() % 200 + 1;
        elementos.push_back(valor);
        validar.push_back(true);
      }
      for (int j = 0; j < repeticiones; j++) {
        auto start = ya();
        int libres = CantidadPosicionesOcupadas(elementos,validar);
        auto end = ya();
        archivo << chrono::duration_cast<std::chrono::milliseconds>(end-start).count()<< "\n";
      }

  }
}




void test_iguales() {
  ofstream archivo ("resultados_iguales_ej1.txt");
  vector<int> elementos;
  vector<bool> validar;
  int valor = 1;
  int saltos = 2;
  int rango = 26;
  int repeticiones = 10;
  archivo << rango <<"\n";
  for (int i = 0; i < rango; i++) {
    int tamanio=saltos*(i+1);
    archivo  << tamanio<< " \n" ;
      for (int j = elementos.size(); j < tamanio; j++) {
        elementos.push_back(valor);
        validar.push_back(true);
      }
      for (int j = 0; j < repeticiones; j++) {
        auto start = ya();
        int libres = CantidadPosicionesOcupadas(elementos,validar);
        auto end = ya();
        archivo << chrono::duration_cast<std::chrono::milliseconds>(end-start).count()<< "\n";
      }

  }
}
int main() {
  backtracking_3();
  //test_iguales();
  //test_random();
  return 0;
}

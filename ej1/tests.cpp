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
  vector<int> random{184,87,178,116,194,136,187,93,50,22,163,28,91,60,164,127,141,27,173,137,12,169,168,30,183,131,63,124,68,136,130,3,23,59,70,168,194,57,12,43,30,174,22,120,185,138,199,125,116,171,14,127};
  vector<bool> validar;
  vector<int> elementos;
  int saltos = 2;
  int rango = 26;
  int repeticiones = 10;
  archivo << rango <<"\n";
  for (int i = 0; i < rango; i++) {
    int tamanio = saltos*(i+1);
    archivo  << tamanio<< " \n" ;
      for (int j = elementos.size(); j < tamanio; j++) {
        elementos.push_back(random[j]);
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

void test_peorcaso() {
  ofstream archivo ("resultados_peor_ej1.txt");
  vector<int> peor{100,1,99,2,98,3,97,4,96,5,95,6,94,7,93,8,92,9,91,10,90,11,89,12,88,13,87,14,86,15,85,16,84,17,83,18,82,19,81,20,80,21,79,22,78,23,77,24,76,25,75,26};
  vector<bool> validar;
  vector<int> elementos;
  int saltos = 2;
  int rango = 20;
  int repeticiones = 5;
  archivo << rango <<"\n";
  for (int i = 0; i < rango; i++) {
    int tamanio = saltos*(i+1);
    archivo  << tamanio<< " \n" ;
      for (int j = elementos.size(); j < tamanio; j++) {
        elementos.push_back(peor[j]);
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


void peorpeorcaso() {
  ofstream archivo ("resultados_peor_peor_ej1.txt");
  vector<int> peor{1,1,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40};
  vector<bool> validar;
  vector<int> elementos;
  int saltos = 2;
  int rango = 16;
  int repeticiones = 5;
  archivo << rango <<"\n";
  for (int i = 0; i < rango; i++) {
    int tamanio = saltos*(i+1);
    archivo  << tamanio<< " \n" ;
      for (int j = elementos.size(); j < tamanio; j++) {
        elementos.push_back(peor[j]);
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
  //backtracking_3();
  //test_iguales();
  //test_random();
  //test_peorcaso();
  peorpeorcaso();
  return 0;
}

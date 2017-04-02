#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include "source.h"
using namespace std;

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
  int fin = 0;
  int inicio = elementos.size()-1;
  SecuDecreciente(elementos,validar,pila,inicio,fin);
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
  int inicio = elementos.size()-1;
  azules(elementos,validar,pila,inicio,0);
  while (pila.size() != 0) {
    cout << elementos[pila.top()]<< endl;
    pila.pop();
  }
}

int main() {
  //decreciente();
  //test_1();
  test_2();
  return 0;
}

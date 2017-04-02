#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <list>
#include <stack>
using namespace std;

// asumiendo que el tamaño del vector de entrada es de por lo menos tres podemos llamar a esta funcion
// inicio y fin son las posiciones del vector de donde debo buscar la secuencia maxima

bool diferencia(int longSecuMaxima, int longPilaActual, int posicion){
  return ( (longPilaActual + posicion) < longSecuMaxima);
  }
void SecuDecreciente(const vector<int> &elementos, vector<bool> &validar,stack<int> &pila,int inicio, int fin ) {
  int iterador = inicio;
  while (iterador >= fin) {
    if (pila.size() == 0) {
      pila.push(iterador);
      validar[iterador] = false;
      }
    else{
      if (elementos[iterador] < elementos[pila.top()] && validar[iterador]) {
        pila.push(iterador);
        validar[iterador] = false;
        }
      }
      iterador = iterador-1;
    }
}
void azules(vector<int> &elementos, vector<bool> &validar,stack<int> &pilaMaxima,int inicio, int fin) {
  stack<int> pila;
  bool notermine = true;
  pila.push(elementos.size()-1); // el primer elemento es el de mas a la derecha
  int iterador = inicio;
  int n = inicio - fin + 1;
  bool decero = false;
  while (notermine && fin <= iterador) {

    int longSecuMaxima = pilaMaxima.size();
    int longPilaActual = pila.size();
    if (decero == true) {
      pila.push(iterador);
      decero = false;
      validar[iterador] = false;
    }
    SecuDecreciente(elementos,validar,pila,iterador,fin);
    if (pilaMaxima.size()<= pila.size()) {
      pilaMaxima = pila;
    }
    if ((pila.size() == n) || diferencia(longSecuMaxima,longPilaActual,pila.top()) ) {
        notermine  = false;
      }
      else{
      iterador = pila.top();
      validar[pila.top()] = true;
      pila.pop();
      if (pila.size()==0) {
          decero = true;
        }
      iterador = iterador-1;
      }
  }
}

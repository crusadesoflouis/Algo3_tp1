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

void SecuCreciente(const vector<int> &elementos,vector<bool> &validar,stack<int> &pila,int inicio,int fin) {
  int iterador = inicio;
  while (iterador <= fin) {
    if (pila.size() == 0) {
      pila.push(iterador);
      validar[iterador] = false;
      }
    else{
      if (elementos[iterador] > elementos[pila.top()] && validar[iterador]) {
        pila.push(iterador);
        validar[iterador] = false;
        }
      }
      iterador = iterador+1;
    }
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
void rojos(const vector<int> &elementos, vector<bool> &validar,stack<int> &pilaMaxima,int inicio, int fin) {
  stack<int> pila;
  bool notermine = true;
  int iterador = inicio;
  while ( (validar[iterador] == false) && (fin > iterador) ) {
    iterador = iterador+1;
  }
  if (iterador <= fin) {
    pila.push(iterador);
  }
  int n = inicio - fin + 1;
  bool decero = false;
  while (notermine && iterador <= fin) {
    if (decero == true) {
      pila.push(iterador);
      decero = false;
      validar[iterador] = false;
    }
    SecuCreciente(elementos,validar,pila,iterador,fin);
    if (pilaMaxima.size()<= pila.size()) {
      pilaMaxima = pila;
    }
    if ((pila.size() == n) || iterador > fin) {
        notermine  = false;
      }
      else{
      iterador = pila.top();
      validar[pila.top()] = true;
      pila.pop();
      if (pila.size()==0) {
          decero = true;
        }
      iterador = iterador+1;
      }
  }
}
void azules(const vector<int> &elementos, vector<bool> &validar,stack<int> &pilaMaxima,int inicio, int fin) {
  stack<int> pila;
  bool notermine = true;
  int iterador = inicio;
  while ( (validar[iterador] == false) && (fin <= iterador) ) {
    iterador = iterador-1;
  }
  cout << " estoy enazules "<< endl;
  cout << "valor de iterador "<< iterador<<endl;
  cout <<  "valor de fin "<< fin<<endl;
  if (fin <= iterador) {
    pila.push(iterador);
    cout << "entre"<< endl;

  }
  int n = inicio - fin + 1;
  bool decero = false;
  while (notermine && fin <= iterador) {
    if (decero == true) {
      pila.push(iterador);
      decero = false;
      validar[iterador] = false;
    }
    SecuDecreciente(elementos,validar,pila,iterador,fin);
    if (pilaMaxima.size()<= pila.size()) {
      pilaMaxima = pila;
    }
    if ((pila.size() == n) || iterador < fin) {
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

void maximizar(const stack<int> &pilaRoja,const stack<int>&pilaAzul,int &ocupados) {
  if (ocupados < pilaAzul.size()+pilaRoja.size()) {
    ocupados = pilaAzul.size()+pilaRoja.size();
  }
}

int CantidadPosicionesOcupadas(const vector<int> &elementos, vector<bool> &validar) {
  int ocupados = 0;
  int fin = elementos.size()-1;
  for (size_t i = 0; i < elementos.size(); i++) {
    int j = i;
    while (j<=fin) {
      stack<int> pilaAzul;
      stack<int> pilaRoja;
      rojos(elementos,validar,pilaRoja,i,fin);
      azules(elementos,validar,pilaAzul,fin,i);
      maximizar(pilaRoja,pilaAzul,ocupados);
      j++;
        cout << " roja "<< endl;
      while (pilaRoja.size() != 0) {
        cout << elementos[pilaRoja.top()]<< endl;;
        validar[pilaRoja.top()] = true;
        pilaRoja.pop();
        }
        cout << " az<pilaAzul "<< endl;
        while (pilaAzul.size() != 0) {
          cout << elementos[pilaAzul.top()]<< endl;;
          validar[pilaAzul.top()] = true;
          pilaAzul.pop();
          }
    }
  }
  return ocupados;
}

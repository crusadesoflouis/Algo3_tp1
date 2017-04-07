#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <list>
#include <stack>
using namespace std;

bool diferencia(int longSecuMaxima, int longPilaActual, int posicion){
  return ( (longPilaActual + posicion) < longSecuMaxima);
  }

//Funcion que dada una pila, agrega todos los elementos del vector que sean mayores al tope
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
//Funcion que dad una pila, agrega todos los elementos del vector que sean menores al tope
void SecuDecreciente(const vector<int> &elementos, vector<bool> &validar,stack<int> &pila,int inicio, int fin ) {
  int iterador = inicio;
  while (iterador <= fin) {
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
      iterador = iterador+1;
    }

}
//esta funcion setea en false los valores de validar  de una pila máxima, es usado para cuando se sale de la funcion azules
//y se entra a la funcion rojos, de manera tal de que la funcion rojos no toque los elementos de la secuencia que se encuentran
//en la otra secuencia.
void EstablecerValidos(stack<int> pilaMaxima,vector<bool> validar) {
  while (pilaMaxima.size() != 0) {
    validar[pilaMaxima.top()] = false;
    pilaMaxima.pop();
  }
}
void subsecuRojaMaxima(const vector<int> &elementos, vector<bool> &validar, stack<int> &pilaMaxima,stack<int> &pila,int fin,int it,int n,bool &notermine) {
  while (pila.size() != 0 && notermine) {

    while (it <= fin && notermine ) {
      SecuCreciente(elementos,validar,pila,it,fin);
      if (pilaMaxima.size()< pila.size()) {
        pilaMaxima = pila;
      }
      if ((pila.size() == n)) {
        notermine = false;
      }
      else{
        it = pila.top()+1;
        validar[pila.top()]= true;
        pila.pop();
      }
    }
    if (pila.size() != 0) {
      it = pila.top()+1;
      validar[pila.top()]= true;
      pila.pop();
    }
  }
}
//toma el vector y da una subsecuencia maxima de elementos crecientes dentro del rango inicio y fin
void rojos(const vector<int> &elementos, vector<bool> &validar,stack<int> &pilaMaxima,int inicio, int fin) {
  stack<int> pila;
  int j = inicio;
  int n = fin - inicio  + 1;
  bool notermine = true;
  while ( (validar[j] == false) && (j <= fin) ) {
    j = j+1;
  }
  if (j > fin) {
    notermine = false;
  }
  while ( (j <= fin) && notermine) {
    pila.push(j);
    validar[j]= false;
    int  it = j;
    subsecuRojaMaxima(elementos,validar,pilaMaxima,pila,fin,it,n,notermine);
    j++;
  }
}
// busca la mejor secuencia entre IT y fin
void subSecuAzulMaxima(const vector<int> &elementos, vector<bool> &validar, stack<int> &pilaMaxima,stack<int> &pila,int fin,int it,int n,bool &notermine) {
  while (pila.size() != 0 && notermine) {
    while (it <= fin && notermine ) {
      SecuDecreciente(elementos,validar,pila,it,fin);
      if (pilaMaxima.size()< pila.size()) {
        pilaMaxima = pila;
      }
      if ((pila.size() == n)) {
        notermine = false;
      }
      else{
        it = pila.top()+1;
        validar[pila.top()]= true;
        pila.pop();
      }
    }
    if (pila.size() != 0) {
      it = pila.top()+1;
      validar[pila.top()]= true;
      pila.pop();
    }
  }
}
//toma el vector y da una subsecuencia minima de elementos crecientes dentro del rango inicio y fin
void azules(const vector<int> &elementos, vector<bool> &validar,stack<int> &pilaMaxima,int inicio, int fin) {
  stack<int> pila;
  int j = inicio;
  int n = fin - inicio  + 1;
  bool notermine = true;
  while ( (validar[j] == false) && (j <= fin) ) {
    j = j+1;
  }
  if (j > fin) {
    notermine = false;
  }
  while ( (j <= fin) && notermine) {
    pila.push(j);
    validar[j]= false;
    int  it = j;
    subSecuAzulMaxima(elementos,validar,pilaMaxima,pila,fin,it,n,notermine);
    j++;
  }

}

void maximizar(const stack<int> &pilaRoja,const stack<int>&pilaAzul,int &ocupados) {
  if (ocupados < pilaAzul.size()+pilaRoja.size()) {
    ocupados = pilaAzul.size()+pilaRoja.size();
  }
}
//función que recorre todas las secuencias posibles que estan dentro del arreglo y analizando cada una de estas cual
//es la sunsecuencia donde hay la mayor cantidad de elementos siendo ocupados
int CantidadPosicionesOcupadas(const vector<int> &elementos, vector<bool> &validar) {
  int ocupados = 0;
  int fin = elementos.size()-1;
  for (size_t i = 0; i < elementos.size(); i++) {
    int j = i;
    while (j<=fin) {
      stack<int> pilaAzul;
      stack<int> pilaRoja;
      rojos(elementos,validar,pilaRoja,i,j);
      EstablecerValidos(pilaRoja,validar);
      azules(elementos,validar,pilaAzul,0,fin);
      EstablecerValidos(pilaAzul,validar);
      maximizar(pilaRoja,pilaAzul,ocupados);
      j++;
      for (int z = 0; z < validar.size(); z++) {
          validar[z]= true;
        }
    }
  }
  int libres = validar.size()- ocupados;
  return libres;
}

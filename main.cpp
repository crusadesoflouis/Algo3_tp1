#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <list>
#include <stack>
using namespace std;

void listas() {
  list<int>  lista;
  lista.push_back(7);
  lista.push_back(3);
  lista.push_back(70);
  lista.push_back(85);
  /*
  for (std::list<int>::iterator it=lista.begin(); it != lista.end(); ++it)
    std::cout << ' ' << *it;
*/
  list<int>::iterator it2 = lista.begin();
    ++it2;
    lista.erase(it2);
    std::cout << " " << *it2;
}
void dameSecuenciaDecreciente(const vector<int> &elementos, vector<bool> &validar,stack<int> &pila,int inicio, int fin ) {
  int iterador = inicio;
  int posicion = inicio;
  while (iterador >= fin) {
    if (pila.size()== 0 ) {
      pila.push(iterador);
      validar[iterador] = false;
      posicion = iterador;
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

void decreciente() {
  vector<int> elementos;
  vector<bool> validar;
  stack<int> pila;
  elementos.push_back(3);
  elementos.push_back(4);
  elementos.push_back(5);
  for (int i = 0; i < 3; i++) {
      validar.push_back(true);
  }
  int inicio = elementos.size()-1;
  int fin = 0;
  dameSecuenciaDecreciente(elementos,validar,pila,inicio,fin);
  while (pila.size() != 0) {
    cout << pila.top()<< endl;;
    pila.pop();
    }
}
bool diferencia(int longSecuMaxima, int longPilaActual, int posicion){
  return ( (longPilaActual + posicion) < longSecuMaxima);
  }
// asumiendo que el tamaño del vector de entrada es de por lo menos tres podemos llamar a esta funcion
// inicio y fin son las posiciones del vector de donde debo buscar la secuencia maxima
void decrecienteMaxima(vector<int> &elementos, vector<bool> &validar,stack<int> &pilaMaxima,int inicio, int fin) {
  stack<int> pila;
  bool notermine = true;
  int longSecuMaxima = pilaMaxima.size();
  int longPilaActual = pila.size();
  int posicion = inicio + 1;
  int i = inicio;
  int f = fin;
  int n = inicio - fin + 1;
  while (notermine || fin <= f) {

    dameSecuenciaDecreciente(elementos,validar,pila,i,f);
    if ((pila.size() == n) || diferencia(longSecuMaxima,longPilaActual,pila.top()) ) {
        notermine  = false;
      }
      else{
        if (pilaMaxima.size()< pila.size()) {
          pilaMaxima = pila;
        }
        pila.pop();
        if (pila.size()==0) {
          i = i-1;
        }
      }
  }

}

int main() {
  //listas();
  //decreciente();
  return 0;
}

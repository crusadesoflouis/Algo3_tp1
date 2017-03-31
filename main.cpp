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
//requiere que la pila tenga almenos un elemento, igual el vector elementos y validar
void dameSecuenciaDecreciente(const vector<int> &elementos, vector<bool> &validar,stack<int> &pila, int fin ) {
  int iterador = pila.top();
  while (iterador >= fin) {
    if (pila.size()== 0 ) {
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

void decreciente() {
  vector<int> elementos;
  vector<bool> validar;
  stack<int> pila;
  elementos.push_back(2);
  elementos.push_back(31);
  elementos.push_back(7);
  for (int i = 0; i < 3; i++) {
      validar.push_back(true);
  }
  int fin = 0;
  pila.push(elementos.size()-1);
  dameSecuenciaDecreciente(elementos,validar,pila,fin);
  while (pila.size() != 0) {
    cout << elementos[pila.top()]<< endl;;
    validar[pila.top()] = true;
    pila.pop();
    }
}
bool diferencia(int longSecuMaxima, int longPilaActual, int posicion){
  return ( (longPilaActual + posicion) < longSecuMaxima);
  }
// asumiendo que el tamaño del vector de entrada es de por lo menos tres podemos llamar a esta funcion
// inicio y fin son las posiciones del vector de donde debo buscar la secuencia maxima
void decrecienteMaxima(vector<int> &elementos, vector<bool> &validar,stack<int> &pilaMaxima, int fin) {
  stack<int> pila;
  bool notermine = true;
  pila.push(elementos.size()-1); // el primer elemento es el de mas a la derecha
  int f = fin;
  int i = pila.top();
  int n = i - fin + 1;
  bool decero = false;
  while (notermine && fin <= i) {
    int longSecuMaxima = pilaMaxima.size();
    int longPilaActual = pila.size();
    if (decero == true) {
      pila.push(elementos[i]);
      decero = false;
      validar[i] = false;
    }
    dameSecuenciaDecreciente(elementos,validar,pila,f);
    if ((pila.size() == n) || diferencia(longSecuMaxima,longPilaActual,pila.top()) ) {
        notermine  = false;
      }
      else{
        if (pilaMaxima.size()<= pila.size()) {
          pilaMaxima = pila;
        }
        validar[pila.top()] = true;
        pila.pop();
        if (pila.size()==0) {
          decero = true;
          i = i-1;
        }
        else{
          i = pila.top();
        }
      }
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
  decrecienteMaxima(elementos,validar,pila,0);

}
int main() {
  //listas();
  //decreciente();
  test_1();
  return 0;
}

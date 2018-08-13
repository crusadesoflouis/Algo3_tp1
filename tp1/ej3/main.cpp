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


int main() {

  int valor=0;
  int tamanio=0;
  cin>>tamanio;
  vector<int>elementos;
  vector<bool>validar;
  for(int i=0;i<tamanio;i++){
    cin>>valor;
    elementos.push_back(valor);
    validar.push_back(true);
  }
  std::cout << "La cantidad de elementos sin pintar es: " <<dinamica(elementos)<< std::endl;
  return 0;
}

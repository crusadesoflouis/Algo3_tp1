#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <fstream>
#include <cstdlib>
#include <chrono>
using namespace std;
void generador_random(){
  ofstream numerosRandom("random.txt");
  numerosRandom << "[";
  int valor = 1000;
  int crece = 1;
  for (size_t i = 0; i < 1001; i++) {

    numerosRandom << valor;
    numerosRandom << ",";
    numerosRandom << crece;
    numerosRandom << ",";
    valor = valor-1;
    crece = crece+1;
  }
  numerosRandom<<"]";
}

int main(int argc, char const *argv[]) {
  generador_random();
  return 0;
}

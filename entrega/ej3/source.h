#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <climits>
using namespace std;

bool PR(int i,int k,const vector<int> &elementos) {
return elementos[i]<elementos[k];
}
bool PA(int j,int k,const vector<int> &elementos) {
return elementos[j]>elementos[k];
}

int upper(int i, int j, vector< vector < int > > &matriz,const  vector <int> &elementos) {
  int max = 0;
  int aux = 0;
  int k = i-1;
  int m = k-1;
  while (m>0) {
    if (PR(m,k,elementos)) {
       aux = 1 + matriz[m+1][j];
      if (max < aux) {
        max = aux;
      }
    }
    m--;
  }
  if (m == 0) {
      if (PR(m,k,elementos)) {
        aux = 1 + matriz[1][j];
        if (max < aux) {
          max = aux;
        }
      }
      m--;
  }

  if ( m < 0 ) {
    aux = 1+matriz[0][j];
    if (max < aux) {
      max = aux;
    }
  }

  return max;
}


int lower(int i, int j, vector< vector < int > > &matriz,const vector <int > &elementos) {
int max = 0;
int aux = 0;
int k = j-1;
int m = k-1;
while (m>0) {
  if (PA(m,k,elementos)) {
    aux = 1 + matriz[i][m+1];
    if (max < aux) {
      max = aux;
    }
  }
  m--;
}
if (m == 0) {
  if (PA(m,k,elementos)) {
    aux = 1+matriz[i][1];
  }
  if (max < aux) {
    max = aux;
  }
  m--;

}

if ( m < 0 ) {
  aux = 1+matriz[i][0];
  if (max < aux) {
    max = aux;
  }
}


return max;
}

void mostrar(vector < vector <int> > &matriz,int n) {
    for (unsigned int i = 0; i < n; ++i)
    {
        for (unsigned int j = 0; j < n; ++j)
        {
            cout << matriz[j][i] << " ";
        }
        cout << std::endl;
    }

}

void inicializar(vector < vector <int > > &matriz,const vector <int> &elementos) {
  matriz[0][1] = 1;
  matriz[1][0] = 1;
  matriz[2][1] = 2;
  matriz[1][2] = 2;
  }

void asignar(int i, int j, vector< vector < int > > &matriz,const vector <int> &elementos) {
  if (not(i == 0 && j == 1 || i == 1 && j == 0 || i == 2 && j == 1 || i == 1 && j == 2)) {
    if (i>j) {
    matriz[i][j] = upper(i,j,matriz,elementos);
    }
    else{
    matriz[i][j] = lower(i,j,matriz,elementos);
    }
  }
}

int MaxMatriz(vector < vector <int> > &matriz,int tam) {
  int max = 0;
for (size_t i = 0; i < tam; i++) {
  for (size_t j = 0; j < tam; j++) {
    if (max < matriz[i][j]) {
      max = matriz[i][j];
    }
  }
}
  return max;
}
int dinamica(const vector<int> &elementos) {
  int MaxTotal = 2;
  int n = elementos.size()+1;
  vector< vector<int> > matriz(n, vector<int>(n,0));
  inicializar(matriz,elementos);
  for (size_t j = 0; j < elementos.size()+1; j++) {
    for (size_t i = 0; i < elementos.size()+1; i++) {
      if (j==i) {
        matriz[i][j] = 0;
      }
      else{
        asignar(i,j,matriz,elementos);
          }
        }
    }
  int maxPintados = MaxMatriz(matriz,elementos.size()+1);
return elementos.size()-maxPintados;
}

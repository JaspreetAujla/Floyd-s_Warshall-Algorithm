#include <iostream>
using namespace std;

#define nV 4

#define INF 9999

void printM(int matrix[][nV]);


void floydWar(int graph[][nV]) 
{
  int matrix[nV][nV], i, j, k;

  for (i = 0; i < nV; i++)
    for (j = 0; j < nV; j++)
      matrix[i][j] = graph[i][j];


  for (k = 0; k < nV; k++) {
    for (i = 0; i < nV; i++) {
      for (j = 0; j < nV; j++) 
      {
        if (matrix[i][k] + matrix[k][j] < matrix[i][j])
          matrix[i][j] = matrix[i][k] + matrix[k][j];
      }
    }
  }
  printM(matrix);
}

void printM(int matrix[][nV])
 {
     cout<< " ALL PAIRS SHORTEST PATH\n";
  for (int i = 0; i < nV; i++) {
    for (int j = 0; j < nV; j++) {
      if (matrix[i][j] == INF)
        cout << "INF" <<" ";
      else
        cout <<  matrix[i][j] << "  ";
    }
    cout << endl;
  }
}

int main() {
  int graph[nV][nV] =
    {
      {  1,     4,     INF,      6},
      {  4,     0,     INF,      5},
      {INF,     2,       3,    INF},
      {INF,     3,       5,      2}
    };

  floydWar(graph);
  return 0;
}
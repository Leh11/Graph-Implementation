#include <vector>
#include <iostream>
using namespace std;

#define INF 10000000
#define n_vertex 5

void prim(int graph[][n_vertex], vector<int> selected)
{
  
  selected[0] = true;

  for(int edge = 0; edge < n_vertex - 1; edge++)
  {
    int min = INF;
    int aux0 = 0;
    int aux1 = 0;

    for (int i = 0; i < n_vertex; i++)
    {
      if (selected[i])
      {
        for (int j = 0; j < n_vertex; j++)
        {
          if ((graph[i][j] && !selected[j]) && (min > graph[i][j]))
          {
            min = graph[i][j];
            aux0 = i;
            aux1 = j;
          }
        }
      }
    }
    cout << aux0<<" - " << aux1<< " -> " << graph[aux0][aux1]<<endl;
    selected[aux1] = true;
  }
}

int main(int argc, char const *argv[])
{
  
  int graph[n_vertex][n_vertex] = {{0, 2, 0, 6, 0},
                                   {1, 0, 3, 8, 5},
                                   {0, 3, 0, 3, 7},
                                   {6, 0, 0, 0, 9},
                                   {0, 2, 6, 9, 0}};

  vector<int> selected(n_vertex, false);

  prim(graph, selected);
  return 0;
}
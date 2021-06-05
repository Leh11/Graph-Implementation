#include "iostream"

#define SIZE 100
#define INF 100000

using namespace std;

typedef struct
{
    int source;
    int dest;
    int weight;
}Graph;
Graph graph[200];

void bellman_ford(int n_vertex, int m_edge, int source)
{
    int distance[SIZE];
    for (int i = 0; i < n_vertex; i++)
    {
        if (i == source)
            distance[i] = 0;
        else
            distance[i] = INF;
    }

    bool flag = false;
    int i = 0;
    while(!flag && (i < n_vertex))
    {
        flag = true;
        for (int j = 0; j < m_edge; j++)
        {
            int u = graph[j].source;
            int v = graph[j].dest;
            if (distance[u] + graph[j].weight < distance[v])
            {
                distance[v] = distance[u] + graph[j].weight;
                flag = false;
            }
        }
        //i++;
    }
    if (!flag){
        cout<<"Ciclo negativo!"<<endl;
    }

    cout << "Distancia de origem ao destino\n";
    for (int i = 0; i < n_vertex; i++){
        cout<< i<<" " <<distance[i] <<endl;
    }
}

int main(int argc, char const *argv[])
{
    int n_vertex = 3;
    int n_edge = 4;
    //Graph graph[n_edge];

    graph[0].source = 0;
    graph[0].dest = 1, 
    graph[0].weight = -1;
    graph[1].source = 0, 
    graph[1].dest = 2, 
    graph[1].weight = 4,
    graph[2].source = 2,
    graph[2].dest = 0,
    graph[2].weight = 6,
    graph[3].source = 1, 
    graph[3].dest = 2, 
    graph[3].weight = -2;


    bellman_ford(n_vertex, n_edge, 0);
    return 0;
}

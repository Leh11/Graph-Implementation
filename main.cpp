#include "kruskal.h"
#include "floyd_warshall.h"
#define INFINIT 1000000

using namespace std;

int main(int argc, char const *argv[])
{
    int num1;
    int n_edge;
    int u, v, weigth;
    
    cin>>num1>>n_edge;

    Graph_k graph_k(num1);

    //inserir no grafo_k para rodar algoritmo de kruskal == MST
    for (int i = 0; i < n_edge; i++)
    {
        cin>>u>>v>>weigth;

        graph_k.add_edge(u, v, weigth);
    }
    
    cout<<"MST by Kruskall"<<endl;
    graph_k.kruskal();
    cout<<"============================="<<endl;

    int num2, w;
    cin >>num2;
    Graph_fw graph_fw(num2);
    //inserir no grafo_fw para rodar floyd_warshall == caminhos curtos;
    for (int i = 0; i < num2; i++)
    {
        for (int j = 0; j < num2; j++)
        {
            cin>>w;
            if (w == -1)
            {
                graph_fw.original[i][j] = INFINIT;
                graph_fw.sol_out[i][j] = INFINIT;
            }else{
                graph_fw.original[i][j] = w;
                graph_fw.sol_out[i][j] = w;
            }
            //cout <<" True: "<<graph_fw.original[i][j];
        }
    }

    cout<<"Short path by Floyd"<<endl;
    graph_fw.floyd_warshall();
    return 0;
}

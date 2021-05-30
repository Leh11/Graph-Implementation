#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Edge_{
    public:
        int weight;
        int source;
        int dest;
};

class Graph_k
{
    public:
        int num_vertex;
        int summ;
        Edge_ edge;
        vector<Edge_> edge_list;
        map<int, int> visited;

    public:
        Graph_k(int u);
        
        void add_edge(int u, int v, int weight);
        void deep_search(int current);
        void unionn(int *p_head, int source, int dest);
        int findd(int u, int *p_head);
        void kruskal();
        ~Graph_k();
};

#include <iostream>
#include "kruskal.h"


Graph_k::Graph_k(int n_vertex){
    this->num_vertex = n_vertex;
    this->summ = 0;
}
Graph_k::~Graph_k() {}

void Graph_k::add_edge(int u_source, int v_dest, int weight)
{
    edge.weight = weight;
    edge.source = u_source;
    edge.dest = v_dest;

    edge_list.push_back(edge);
}

int Graph_k::findd(int u, int *p_head)
{
    if (u == p_head[u])
    {
        return u;
    }
    return findd(p_head[u], p_head);
}

void Graph_k::unionn(int *p_head, int source, int dest)
{
    p_head[source] = dest;
}

int compare(Edge_ ed1, Edge_ ed2){
    return ed1.weight < ed2.weight;
}

void Graph_k::kruskal()
{
    vector<Edge_> MST;
    int *p_head = new int[num_vertex];

    for (int i = 0; i < num_vertex; i++)
    {
        p_head[i] = i;
    }
    
    sort(edge_list.begin(), edge_list.end(), compare);

        for (int i = 0; i < edge_list.size(); i++)
        {
            int u = findd(edge_list[i].source, p_head);
            int v = findd(edge_list[i].dest, p_head);

            if (u != v)
            {
                MST.push_back(edge_list[i]);
                summ += edge_list[i].weight;
                unionn(p_head, u, v);
            }
            //cout <<"Vert: "<<aux.source<<"-"<<aux.dest<<" -->"<<aux.weight<<endl;
    }
    
    for (int i = 0; i < MST.size(); i++)
    {
        cout <<"("<<MST[i].source <<"--" 
        <<MST[i].dest << ")"<<" = "
        <<MST[i].weight <<endl;
    }

    cout <<"Cost: "<<summ << endl;
}
/*void Graph_k::deep_search(int current)
{

    visited[current] = true;
    cout << "Visiting: " << current << endl;
    
    for (Edge_ edge : adj_list[current])
    {
        if (!visited[edge.dest])
        {
            deep_search(edge.dest);
        }
    }
}*/

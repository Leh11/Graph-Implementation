#include <iostream>
#include <limits.h>
#include "floyd_warshall.h"
#define INFINIT 10000

Graph_fw::Graph_fw(int num)
{
    size = num;
    sol_out = new int*[num];
    original = new int*[num];

    for (int i = 0; i < num; i++)
    {
        sol_out[i] = new int[num];
        original[i] = new int[num];
    }
}

Graph_fw::~Graph_fw()
{
    for (int i = 0; i < size; i++)
    {
        delete[] sol_out[i];
        delete[] original[i];
    }
    delete[] sol_out;
    delete[] original;
}

void Graph_fw::floyd_warshall()
{
    for (int k = 0; k < size; k++)
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                sol_out[i][j] = std::min(sol_out[i][j], sol_out[i][k] + sol_out[k][j]);
            }
        }
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (sol_out[i][j] == INFINIT)
            {
                std::cout<< "INFINIT ";
            }else{
                std::cout<<" " <<sol_out[i][j];
            }
        }
        std::cout <<"\n";
    }
}

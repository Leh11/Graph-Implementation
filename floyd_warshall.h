#include <iostream>

class Graph_fw
{
    public:
        int size;
        int **sol_out;
        int **original;

    public:
        Graph_fw(int num);
    
        void floyd_warshall();
        ~Graph_fw();
};

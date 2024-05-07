//id: 318876406
//email: erikidelchik@gmail.com

#include <vector>
#include <iostream>
#include "Graph.hpp"
#include <limits.h>

#define BLACK 1
#define WHITE 2

namespace ariel{

    int rowIsZero(vector<vector<int>>, int);
    int colIsZero(vector<vector<int>>, int);
    int min(int,int);

    class Algorithms{
    public:
        static int isConnected(Graph graph);
        static string shortestPath(Graph graph, int src, int dest);
        static string isContainsCycle(Graph graph);
        static string isBipartite(Graph graph);
        static string negativeCycle(Graph graph);
    };



    class Vertex{
    public:
        int key;
        int pi;
        vector<int> neighbors;
        int color;
        void setColor(int c){
            this->color = c;
        }
    };


}

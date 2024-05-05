#include <iostream>
#include <vector>

using namespace std;

namespace ariel {
    class Graph {
        vector<vector<int>> myGraph;

    public:
        void setGraph(int i,int j,int value);

        vector<vector<int>> getGraph();

        void loadGraph(vector<vector<int>> mat);

        void printGraph();
    };
}

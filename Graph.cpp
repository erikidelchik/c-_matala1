#include <iostream>
#include <vector>
#include "Graph.hpp"


namespace ariel {

        vector<vector<int>> Graph::getGraph() {
            return this->myGraph;
        }
        void Graph::setGraph(int i,int j,int value){
            myGraph[i][j]=value;
        }

        void Graph::loadGraph(vector<vector<int>> mat) {
            if (!myGraph.empty()) myGraph.clear();
            for (int i = 0; i < mat.size(); i++) {
                if (mat.size() != mat[i].size()) {
                    throw std::invalid_argument("Invalid graph: The graph is not a square matrix.");
                }
            }
            for (int i = 0; i < mat.size(); i++) {
                myGraph.push_back(mat[i]);
            }
        }

        void Graph::printGraph() {
            if (myGraph.empty()) throw string("graph is empty");
            int vertices = (int) myGraph.size();
            int edges = 0;

//        bool directed = true;
//        //check if the graph is directed
//        for(int i=0;i<myGraph.size();i++){
//            for(int j=i;j<myGraph.size();j++) {
//                if(myGraph[i][j]==myGraph[j][i]) continue;
//                else{
//                    directed = true;
//                    break;
//                }
//
//            }
//        }

            //count edges
            for (int i = 0; i < myGraph.size(); i++) {
                for (int j = i; j < myGraph.size(); j++) {
                    if ((myGraph[i][j] && !myGraph[j][i]) || (!myGraph[i][j] && myGraph[j][i]))
                        edges++;
                    else if (myGraph[i][j] && myGraph[j][i])
                        edges += 2;

                }
            }
            cout << "Graph with " << vertices <<" vertices and " << edges<<" edges" << endl;

        }

}



//int main() {
//    Graph g;
//    vector<vector<int>> mat = {{1,2,3},{4,5,6}};
//    try {
//        g.loadGraph(mat);
//    }
//    catch (const std::invalid_argument &e){
//        cout << e.what() << endl;
//    }
//    g.loadGraph(mat);
//    for(int i=0;i<g.getGraph().size();i++){
//        for(int j=0;j<g.getGraph()[0].size();j++){
//            cout<<g.getGraph()[i][j]<<' ';
//        }
//        cout<<endl;
//    }
//    return 0;
//}


//id: 318876406
//email: erikidelchik@gmail.com

#include <iostream>
#include <vector>
#include <stack>
#include "Algorithms.hpp"

using ariel::Algorithms;
using namespace std;
namespace ariel {

    int min(int a, int b) {

        return a<b ? a:b;
    }
    bool contains(int x,vector<int> list){
        for(int i:list){
            if (i==x) return true;
        }
        return false;
    }


    int Algorithms::isConnected(ariel::Graph graph) {
        for (int i = 0; i < graph.getGraph().size(); i++) {
            if (rowIsZero(graph.getGraph(), i) && colIsZero(graph.getGraph(), i)) return 0;
        }
        return 1;
    }

    int minDistance(const vector<Vertex> &vertexes, bool checked[])
    {

        // Initialize min value
        int min = INT_MAX;
        int min_index;

        for (int v = 0; v < vertexes.size(); v++)
            if (!checked[v] && vertexes[v].key <= min)
                min = vertexes[v].key, min_index = v;

        return min_index;
    }

    //return -1 if no negative cycle, otherwise return the number of the vertex from which the negative cycle starts
    int bellmanFord(vector<Vertex> &vertexes,Graph graph,int src) {
        for(int i=0;i<vertexes.size();i++){
            for(int j=0;j<vertexes.size();j++){
                if(graph.getGraph()[i][j] == 0)
                    graph.setGraph(i,j,INT_MAX);
            }
        }

        bool* checked = new bool[vertexes.size()];
        for(int i=0;i<vertexes.size();i++){
            vertexes[i].key = INT_MAX;
            vertexes[i].pi = -1;
            checked[i]= false;
        }

        vertexes[src].key = 0;


        //bellman ford
        for(int n=0;n<vertexes.size()-1;n++) {

            for (int i=0;i<vertexes.size()-1;i++) {
                int u = minDistance(vertexes,checked);

                checked[u] = true;

                for (int v: vertexes[u].neighbors) {
                    if (vertexes[u].key != INT_MAX && !checked[v] && vertexes[u].pi!=v) {

                        //relax()
                        if (vertexes[v].key > vertexes[u].key + graph.getGraph()[u][v]) {
                            vertexes[v].key = vertexes[u].key + graph.getGraph()[u][v];
                            vertexes[v].pi = u;

                        }
                    }
                }

            }
            for(int i=0;i<vertexes.size();i++){
                checked[i] = false;
            }
        }



        //check for negative cycle

        for (int i=0;i<vertexes.size()-1;i++) {

            int u = minDistance(vertexes,checked);
            checked[u] = true;

            for (int v: vertexes[u].neighbors) {
                if (vertexes[u].key != INT_MAX && !checked[v] && vertexes[u].pi!=v) {

                    //relax()
                    if (vertexes[v].key > vertexes[u].key + graph.getGraph()[u][v]) {
                        delete []checked;
                        return u;


                    }
                }
            }
        }

        delete []checked;

        return -1;
    }

    string Algorithms::shortestPath(ariel::Graph graph, int src, int dest) {
        if(src==dest) return "0";
        //list of vertexes
        vector<Vertex> vertexes(graph.getGraph().size());


        //get list of neighbors
        for(int i=0;i<vertexes.size();i++){
            for(int j=0;j<vertexes.size();j++){
                if(graph.getGraph()[i][j]){
                    vertexes[i].neighbors.push_back(j);
                }
            }
        }


        if(bellmanFord(vertexes,graph,src)!=-1) return "-1";


        vector<int> path;
        int desttemp = dest;


        //build path
        while (vertexes[desttemp].pi != src) {
            if(vertexes[desttemp].pi==-1) return "-1";
            path.push_back(vertexes[desttemp].pi);
            desttemp = vertexes[desttemp].pi;

        }

        path.push_back(src);
        string str = "";
        for (int i = (int) path.size() - 1; i >= 0; i--) {
            str+= std::to_string(path[i]);
            str+="->";
        }
        str+= std::to_string(dest);
        return str;
    }



    void findCycle(int vi,vector<Vertex>& vertexes,int s){
        for(int i:vertexes[vi].neighbors){
            if(vertexes[i].color==WHITE){
                vertexes[i].setColor(BLACK);
                vertexes[i].pi = vi;
                vertexes[i].key = vertexes[vi].key+1;
                findCycle(i,vertexes,s);

            }
            else{
                if(i==s && vertexes[vi].key>1) {
                    vertexes[s].pi = vi;
                    return;
                }
            }

        }
    }

    void setVtoDefault(vector<Vertex> &vertexes){
        for(int i=0;i<vertexes.size();i++) {
            vertexes[i].setColor(WHITE);
            vertexes[i].pi = -1;
            vertexes[i].key = INT_MAX;
        }
    }

    string Algorithms::isContainsCycle(ariel::Graph graph){

        int size = graph.getGraph().size();
        vector<Vertex> vertexes(size);
        //make a list of neighbors for each vertex
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                if(graph.getGraph()[i][j] && i!=j){
                    vertexes[i].neighbors.push_back(j);
                }
            }
        }

        vector<int> path;
        int k=0;
        int src= 0;
        for(int i=0;i<size;i++){
            setVtoDefault(vertexes);
            vertexes[i].key = 0;
            vertexes[i].color = BLACK;
            findCycle(i,vertexes,src);
            if(vertexes[i].pi!=-1){
                break;
            }

            k++;
            src++;
        }
        if(k==size) return "0";


        while (vertexes[k].pi!=src){
            path.push_back(vertexes[k].pi);
            k = vertexes[k].pi;
        }
        string str = "";
        str+= to_string(src);
        str+="->";

        for(int i=path.size()-1;i>=0;i--){
            str+= to_string(path[i]);
            str+="->";
        }
        path.push_back(src);
        str+= to_string(path[path.size()-1]);
        return str;

    }

    string Algorithms::isBipartite(ariel::Graph graph){
        if(graph.getGraph().size()<=1 || !isConnected(graph)) return "0";
        //list of vertexes
        int size = graph.getGraph().size();
        vector<Vertex> vertexes(size);

        //get list of neighbors
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                if(graph.getGraph()[i][j]){
                    vertexes[i].neighbors.push_back(j);
                }
            }
        }

        vector<int> a;
        vector<int> b;
        a.push_back(0);
        vector<bool> visited(size,false);


        for(int i=0;i<size;i++){
            if(i%2==0){
                for(int j:a){
                    if(!visited[j])
                        visited[j] = true;
                    for (int k: vertexes[j].neighbors) {
                        if (!visited[k]) {
                            visited[k] = true;
                            b.push_back(k);
                        }
                    }

                }
            }
            else{
                for(int j:b){
                    if(!visited[j])
                        visited[j] = true;
                    for (int k: vertexes[j].neighbors) {
                        if (!visited[k]) {
                            visited[k] = true;
                            a.push_back(k);
                        }
                    }

                }
            }
        }



        for(int i:a){
            if(contains(i,b)) return "0";
        }

        for(int i:a){
            for(int j:a){
                if(graph.getGraph()[i][j]!=0) return "0";
            }
        }
        for(int i:b){
            for(int j:b){
                if(graph.getGraph()[i][j]!=0) return "0";
            }
        }



        string str = "A={";
        for(int i=0;i<a.size()-1;i++){
            str+= to_string(a[i]);
            str+=", ";
        }
        str+= to_string(a[a.size()-1]);
        str+="}, B={";
        for(int i=0;i<b.size()-1;i++){
            str+= to_string(b[i]);
            str+=", ";
        }
        str+= to_string(b[b.size()-1]);
        str+="}.";
        return str;
    }


    void findNegativeCycle(int vi,vector<Vertex>& vertexes,stack<int> &st){

        st.push(vi);
        int curr = vertexes[vi].pi;

        while(curr!=vi){
            st.push(curr);
            curr = vertexes[curr].pi;
        }

    }



    string Algorithms::negativeCycle(ariel::Graph graph){
        int size = graph.getGraph().size();
        vector<Vertex> vertexes(size);
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                if(graph.getGraph()[i][j]){
                    vertexes[i].neighbors.push_back(j);
                }
            }
        }

        stack<int> st;

        int src;
        for(int i=0;i<size;i++){



            src = bellmanFord(vertexes,graph,i);
            if(src!=-1){
                findNegativeCycle(src,vertexes,st);
                string str = "";
                str+= to_string(src);
                str+="->";
                while(st.size()>1){
                    str+= to_string(st.top());
                    str+="->";
                    st.pop();
                }
                str+= to_string(st.top());
                st.pop();
                return str;
            }

        }
        return "there is no negative cycle";

    }

    
    int rowIsZero(vector<vector<int>> g, int row) {
        for(int i = 0; i < g.size(); i++) {
            if (g[row][i] != 0) return 0;
        }
        return 1;
    }

    int colIsZero(vector<vector<int>> g, int col) {
        for(int i = 0; i < g.size(); i++) {
            if (g[i][col] != 0) return 0;
        }
        return 1;
    }

}

}


#include "doctest.h"

#include "Algorithms.hpp"





using namespace std;



TEST_CASE("load empty Graph"){



    ariel::Graph g;

    vector<vector<int>> graph = {{}};

    CHECK_THROWS(g.loadGraph(graph));



}



TEST_CASE("load non square matrix graph"){

    ariel::Graph g;

    vector<vector<int>> graph = {{1,2}};

    CHECK_THROWS(g.loadGraph(graph));



    vector<vector<int>> graph1 = {{1},

                                  {2}};

    CHECK_THROWS(g.loadGraph(graph1));



    vector<vector<int>> graph2 = {

            {0, 1, 0},

            {1, 1},

            {0, 1, 0}};

    CHECK_THROWS(g.loadGraph(graph2));



    vector<vector<int>> graph3 = {

            {0, 1},

            {1, 1},

            {0, 1}};

    CHECK_THROWS(g.loadGraph(graph3));



}



TEST_CASE("load graph with an edge from a vertex to itself"){

    ariel::Graph g;

    vector<vector<int>> graph3 = {

            {0, 1, 0},

            {1, 1, 1},

            {0, 1, 0}};

    CHECK_THROWS(g.loadGraph(graph3));

}



TEST_CASE("shortest path for positive graphs"){

    ariel::Graph g;



    vector<vector<int>> graph = {

            {0, 1, 0},

            {1, 0, 1},

            {0, 1, 0}};

    g.loadGraph(graph);

    CHECK(ariel::Algorithms::shortestPath(g,0,2) == "0->1->2");





    vector<vector<int>> graph1 = {

            {0, 1, 2, 0, 0},

            {1, 0, 3, 0, 0},

            {2, 3, 0, 4, 0},

            {0, 0, 4, 0, 5},

            {0, 0, 1, 5, 0}};



    g.loadGraph(graph1);

    CHECK(ariel::Algorithms::shortestPath(g,4,1)=="4->2->1");



}



TEST_CASE("shortest path for negative graphs"){

    ariel::Graph g;



    vector<vector<int>> graph = {

            {0, 1, 2, 0, 0},

            {1, 0, -3, 0, 0},

            {2, -3, 0, 4, 0},

            {0, 0, 4, 0, 5},

            {0, 0, 0, 5, 0}};

    g.loadGraph(graph);



    CHECK(ariel::Algorithms::shortestPath(g,0,4)=="0->1->2->3->4");





    vector<vector<int>> graph1 = {

            {0, 1, -2, 0, 0},

            {1, 0, -4, 0, 0},

            {-2, -4, 0, 4, 0},

            {0, 0, 4, 0, 5},

            {0, 2, 0, 5, 0}};

    g.loadGraph(graph1);



    CHECK(ariel::Algorithms::shortestPath(g,4,0)=="-1");



}



TEST_CASE("isContainsCycle directed graphs"){

    ariel::Graph g;



    vector<vector<int>> graph = {

            {0, 1, 0, 0},

            {0, 0, -3, 0},

            {0, 3, 0, 2},

            {2, 0, 0, 0}};

    g.loadGraph(graph);

    CHECK(ariel::Algorithms::isContainsCycle(g)=="0->1->2->3->0");



    vector<vector<int>> graph1 = {

            {0, 0, 0, 0, 0},

            {5, 0, -4, 0, 0},

            {-2, -4, 0, 4, 0},

            {0, 0, 4, 0, 2},

            {0, 1, 0, 2, 0}};

    g.loadGraph(graph1);

    CHECK(ariel::Algorithms::isContainsCycle(g)=="1->2->3->4->1");



    vector<vector<int>> graph2 = {

            {0, 0, 0, 0, 0},

            {5, 0, -4, 0, 0},

            {-2, -4, 0, 4, 0},

            {0, 0, 4, 0, 2},

            {1, 0, 0, 2, 0}};

    g.loadGraph(graph2);



    CHECK(ariel::Algorithms::isContainsCycle(g)=="0");



}



TEST_CASE("isContainsCycle undirected graphs"){

    ariel::Graph g;



    vector<vector<int>> graph = {

            {0, 0, 2, 0, 0},

            {0, 0, -3, 0, 0},

            {2, -3, 0, 4, 1},

            {0, 0, 4, 0, 5},

            {0, 0, 1, 5, 0}};

    g.loadGraph(graph);

    CHECK(ariel::Algorithms::isContainsCycle(g)=="2->3->4->2");



    vector<vector<int>> graph2 = {

            {0, 1, 1},

            {1, 0, 1},

            {1, 1, 0}};

    g.loadGraph(graph2);



    CHECK(ariel::Algorithms::isContainsCycle(g)=="0->1->2->0");



}





TEST_CASE("isBipartite"){

    ariel::Graph g;

    vector<vector<int>> graph = {

            {0, 1, 0, 0, 0},

            {1, 0, 3, 0, 0},

            {0, 3, 0, 4, 0},

            {0, 0, 4, 0, 5},

            {0, 0, 0, 5, 0}};

    g.loadGraph(graph);

    CHECK(ariel::Algorithms::isBipartite(g) == "A={0, 2, 4}, B={1, 3}.");





    vector<vector<int>> graph1 = {

            {0, 0, 1, 1, 0},

            {0, 0, 0, 1, 1},

            {1, 0, 0, 0, 0},

            {1, 1, 0, 0, 0},

            {0, 1, 0, 0, 0}};

    g.loadGraph(graph1);

    CHECK(ariel::Algorithms::isBipartite(g) == "A={0, 1}, B={2, 3, 4}.");



    vector<vector<int>> graph2 = {

            {0, 0, 1, 0, 1},

            {0, 0, 1, 1, 1},

            {1, 1, 0, 0, 0},

            {0, 1, 0, 0, 0},

            {1, 1, 0, 0, 0}};

    g.loadGraph(graph2);

    CHECK(ariel::Algorithms::isBipartite(g) == "A={0, 1}, B={2, 4, 3}.");





    vector<vector<int>> graph3 = {

            {0, 1, 1, 0, 0},

            {1, 0, 0, 0, 0},

            {1, 0, 0, 1, 0},

            {0, 0, 1, 0, 1},

            {0, 0, 0, 1, 0}};

    g.loadGraph(graph3);

    CHECK(ariel::Algorithms::isBipartite(g) == "A={0, 3}, B={1, 2, 4}.");

}



TEST_CASE("negative cycle on directed graphs"){

    ariel::Graph g;

    vector<vector<int>> graph = {

            {0, 1, 0, 0, -1},

            {0, 0, -2, 0, 0},

            {0, 0, 0, -1, 0},

            {0, 0, 0, 0, 1},

            {-2, 0, 0, 0, 0}};

    g.loadGraph(graph);

    CHECK(ariel::Algorithms::negativeCycle(g)=="2->3->4->0->1->2");



    vector<vector<int>> graph1 = {

            {0, 1, 0, 0, 1},

            {1, 0, -1, 0, 0},

            {0, 1, 0, -1, 0},

            {-1, 0, 2, 0, 1},

            {2, 0, 0, 0, 0}};

    g.loadGraph(graph1);

    CHECK(ariel::Algorithms::negativeCycle(g)=="2->3->0->1->2");



}



TEST_CASE("negative cycle on undirected graphs"){

    ariel::Graph g;

    vector<vector<int>> graph = {

            {0, 1, -2, 0, 0},

            {1, 0, -1, 0, 0},

            {-2, -1, 0, 4, 0},

            {0, 0, 4, 0, 5},

            {0, 0, 0, 5, 0}};

    g.loadGraph(graph);

    CHECK(ariel::Algorithms::negativeCycle(g)=="2->0->1->2");



    vector<vector<int>> graph1 = {

            {0, 3, 0, 0, 1},

            {3, 0, 1, -1, 0},

            {0, 1, 0, -3, 0},

            {0, -1, -3, 0, 1},

            {1, 0, 0, 1, 0}};

    g.loadGraph(graph1);

    CHECK(ariel::Algorithms::negativeCycle(g)=="3->2->1->3");



    vector<vector<int>> graph2 = {

            {0, 3, 0, 0, -3},

            {3, 0, 4, 1, 0},

            {0, 4, 0, -2, 0},

            {0, 1, -2, 0, 1},

            {-3, 0, 0, 1, 0}};

    g.loadGraph(graph2);

    CHECK(ariel::Algorithms::negativeCycle(g)=="there is no negative cycle");



}





TEST_CASE(">"){

    ariel::Graph g1;

    ariel::Graph g2;



    vector<vector<int>> graph1 = {

            {0, 1, 0},

            {1, 0, 1},

            {0, 1, 0}};

    g1.loadGraph(graph1);



    vector<vector<int>> graph2 = {

            {0, 1, 1},

            {1, 0, 1},

            {0, 1, 0}};

    g2.loadGraph(graph2);



    CHECK_EQ((g2>g1),true);

    CHECK_EQ((g1>g2),false);



}



TEST_CASE(">="){

    ariel::Graph g1;

    ariel::Graph g2;



    vector<vector<int>> graph1 = {

            {0, 1, 0},

            {1, 0, 1},

            {0, 1, 0}};

    g1.loadGraph(graph1);



    vector<vector<int>> graph2 = {

            {0, 1, 1},

            {1, 0, 1},

            {0, 1, 0}};

    g2.loadGraph(graph2);



    CHECK_EQ((g2>=g1),true);

    CHECK_EQ((g1>=g2),false);



    vector<vector<int>> graph3 = {

            {0, 3, 0, 0, 1},

            {3, 0, 1, -1, 0},

            {0, 1, 0, -3, 0},

            {0, -1, -3, 0, 1},

            {1, 0, 0, 1, 0}};

    g1.loadGraph(graph3);



    vector<vector<int>> graph4 = {

            {0, 3, 0, 0, 1},

            {3, 0, 1, -1, 0},

            {0, 1, 0, -3, 0},

            {0, -1, -3, 0, 1},

            {1, 0, 0, 1, 0}};

    g2.loadGraph(graph4);



    CHECK_EQ((g1>=g2),true);

    CHECK_EQ((g2>=g1),true);



}



TEST_CASE("<"){

    ariel::Graph g1;

    ariel::Graph g2;



    vector<vector<int>> graph1 = {

            {0, 1, 1},

            {1, 0, 1},

            {0, 1, 0}};

    g1.loadGraph(graph1);



    vector<vector<int>> graph2 = {

            {0, 1, 1},

            {1, 0, 1},

            {1, 1, 0}};

    g2.loadGraph(graph2);



    CHECK_EQ((g2<g1),false);

    CHECK_EQ((g1<g2),true);



}



TEST_CASE("<="){

    ariel::Graph g1;

    ariel::Graph g2;



    vector<vector<int>> graph1 = {

            {0, 1, 1},

            {1, 0, 1},

            {0, 1, 0}};

    g1.loadGraph(graph1);



    vector<vector<int>> graph2 = {

            {0, 1, 1},

            {1, 0, 1},

            {1, 1, 0}};

    g2.loadGraph(graph2);



    CHECK_EQ((g2<=g1),false);

    CHECK_EQ((g1<=g2),true);



}



TEST_CASE("=="){

    ariel::Graph g1;

    ariel::Graph g2;



    vector<vector<int>> graph1 = {

            {0, 1, 0},

            {1, 0, 1},

            {0, 1, 0}};

    g1.loadGraph(graph1);



    vector<vector<int>> graph2 = {

            {0, 0, 1},

            {0, 0, 1},

            {1, 1, 0}};

    g2.loadGraph(graph2);



    CHECK_EQ((g1==g2),false);



    vector<vector<int>> graph3 = {

            {0, 1, 0},

            {1, 0, 1},

            {0, 1, 0}};

    g1.loadGraph(graph3);



    vector<vector<int>> graph4 = {

            {0, 1, 0},

            {1, 0, 1},

            {0, 1, 0}};

    g2.loadGraph(graph4);



    CHECK_EQ((g1==g2),true);

}





TEST_CASE("g--"){

    ariel::Graph g1;

    ariel::Graph g2;



    vector<vector<int>> graph1 = {

            {0, 1, 0},

            {1, 0, 1},

            {0, 1, 0}};

    g1.loadGraph(graph1);



    vector<vector<int>> graph2 = {

            {0, 0, -1},

            {0, 0, 0},

            {-1, 0, 0}};

    g2.loadGraph(graph2);



    g1--;

    CHECK_EQ(g1,g2);





    vector<vector<int>> graph3 = {

            {0, 1, 0},

            {1, 0, 1},

            {0, 1, 0}};

    g1.loadGraph(graph3);



    vector<vector<int>> graph4 = {

            {0, 1, 0},

            {1, 0, 1},

            {0, 1, 0}};

    g2.loadGraph(graph4);



    CHECK_EQ(g1--,g2);

}



TEST_CASE("--g"){

    ariel::Graph g1;

    ariel::Graph g2;



    vector<vector<int>> graph1 = {

            {0, 1, 0},

            {1, 0, 1},

            {0, 1, 0}};

    g1.loadGraph(graph1);



    vector<vector<int>> graph2 = {

            {0, 0, -1},

            {0, 0, 0},

            {-1, 0, 0}};

    g2.loadGraph(graph2);



    CHECK_EQ(--g1,g2);

}



TEST_CASE("g++"){

    ariel::Graph g1;

    ariel::Graph g2;



    vector<vector<int>> graph1 = {

            {0, 1, 0},

            {1, 0, 1},

            {0, 1, 0}};

    g1.loadGraph(graph1);



    vector<vector<int>> graph2 = {

            {0, 2, 1},

            {2, 0, 2},

            {1, 2, 0}};

    g2.loadGraph(graph2);



    g1++;

    CHECK_EQ(g1,g2);





    vector<vector<int>> graph3 = {

            {0, 1, 0},

            {1, 0, 1},

            {0, 1, 0}};

    g1.loadGraph(graph3);



    vector<vector<int>> graph4 = {

            {0, 1, 0},

            {1, 0, 1},

            {0, 1, 0}};

    g2.loadGraph(graph4);



    CHECK_EQ(g1++,g2);



}



TEST_CASE("++g"){

    ariel::Graph g1;

    ariel::Graph g2;



    vector<vector<int>> graph1 = {

            {0, 1, 0},

            {1, 0, 1},

            {0, 1, 0}};

    g1.loadGraph(graph1);



    vector<vector<int>> graph2 = {

            {0, 2, 1},

            {2, 0, 2},

            {1, 2, 0}};

    g2.loadGraph(graph2);



    CHECK_EQ(++g1,g2);

}



TEST_CASE("+"){

    ariel::Graph g1;

    ariel::Graph g2;

    ariel::Graph g3;

    ariel::Graph g4;



    vector<vector<int>> graph1 = {

            {0, 1, 0},

            {1, 0, 1},

            {0, 1, 0}};

    g1.loadGraph(graph1);



    vector<vector<int>> graph2 = {

            {0, 2, 0},

            {2, 0, 2},

            {0, 2, 0}};

    g2.loadGraph(graph2);



    vector<vector<int>> graph3 = {

            {0, 3, 0},

            {3, 0, 3},

            {0, 3, 0}};

    g3.loadGraph(graph3);



    g4 = g1+g2;



    CHECK_EQ(g3,g4);

}





TEST_CASE("-"){

    ariel::Graph g1;

    ariel::Graph g2;

    ariel::Graph g3;





    vector<vector<int>> graph1 = {

            {0, 1, 0},

            {1, 0, 1},

            {0, 1, 0}};

    g1.loadGraph(graph1);



    vector<vector<int>> graph2 = {

            {0, 2, 0},

            {2, 0, 2},

            {0, 2, 0}};

    g2.loadGraph(graph2);



    vector<vector<int>> graph3 = {

            {0, 3, 0},

            {3, 0, 3},

            {0, 3, 0}};

    g3.loadGraph(graph3);







    CHECK_EQ(g3-g2,g1);

}





TEST_CASE("+="){

    ariel::Graph g1;

    ariel::Graph g2;

    ariel::Graph g3;





    vector<vector<int>> graph1 = {

            {0, 1, 0},

            {1, 0, 1},

            {0, 1, 0}};

    g1.loadGraph(graph1);



    vector<vector<int>> graph2 = {

            {0, 2, 0},

            {2, 0, 2},

            {0, 2, 0}};

    g2.loadGraph(graph2);



    vector<vector<int>> graph3 = {

            {0, 3, 0},

            {3, 0, 3},

            {0, 3, 0}};

    g3.loadGraph(graph3);



    g1+=g2;



    CHECK_EQ(g3,g1);

}



TEST_CASE("-="){

    ariel::Graph g1;

    ariel::Graph g2;

    ariel::Graph g3;





    vector<vector<int>> graph1 = {

            {0, 1, 0},

            {1, 0, 1},

            {0, 1, 0}};

    g1.loadGraph(graph1);



    vector<vector<int>> graph2 = {

            {0, 2, 0},

            {2, 0, 2},

            {0, 2, 0}};

    g2.loadGraph(graph2);



    vector<vector<int>> graph3 = {

            {0, 3, 0},

            {3, 0, 3},

            {0, 3, 0}};

    g3.loadGraph(graph3);



    g3-=g2;



    CHECK_EQ(g3,g1);

}



TEST_CASE("g1 * g2"){

    ariel::Graph g1;

    ariel::Graph g2;

    ariel::Graph g3;



    vector<vector<int>> graph4 = {

            {0, 0, 2},

            {0, 0, 0},

            {1, 0, 0}};

    g1.loadGraph(graph4);



    vector<vector<int>> graph5 = {

            {0, 2, 0},

            {1, 0, 2},

            {0, 2, 0}};

    g2.loadGraph(graph5);



    vector<vector<int>> graph6 = {

            {0, 4, 0},

            {0, 0, 0},

            {0, 2, 0}};

    g3.loadGraph(graph6);



    CHECK_EQ(g1*g2,g3);

}





TEST_CASE("g1 * g2 - when the answer is invalid graph"){

    ariel::Graph g1;

    ariel::Graph g2;



    vector<vector<int>> graph1 = {

            {0, 1, 0},

            {1, 0, 1},

            {0, 1, 0}};

    g1.loadGraph(graph1);



    vector<vector<int>> graph2 = {

            {0, 2, 0},

            {2, 0, 2},

            {0, 2, 0}};

    g2.loadGraph(graph2);



    CHECK_THROWS(g1*g2);

}





TEST_CASE("g1 * g2 - when graphs not of the same size"){

    ariel::Graph g1;

    ariel::Graph g2;



    vector<vector<int>> graph1 = {

            {0, 1, 0},

            {1, 0, 1},

            {0, 1, 0}};

    g1.loadGraph(graph1);



    vector<vector<int>> graph2 = {

            {0, 3, 0, 0, 1},

            {3, 0, 1, -1, 0},

            {0, 1, 0, -3, 0},

            {0, -1, -3, 0, 1},

            {1, 0, 0, 1, 0}};

    g2.loadGraph(graph2);



    CHECK_THROWS(g1*g2);



}



TEST_CASE("g * int"){

    ariel::Graph g1;

    ariel::Graph g2;

    ariel::Graph g3;





    vector<vector<int>> graph1 = {

            {0, 1, 0},

            {1, 0, 1},

            {0, 1, 0}};

    g1.loadGraph(graph1);



    vector<vector<int>> graph2 = {

            {0, 2, 0},

            {2, 0, 2},

            {0, 2, 0}};

    g2.loadGraph(graph2);



    CHECK_EQ(g1 * 2,g2);

}



TEST_CASE("int * g"){

    ariel::Graph g1;

    ariel::Graph g2;

    ariel::Graph g3;





    vector<vector<int>> graph1 = {

            {0, 1, 0},

            {1, 0, 1},

            {0, 1, 0}};

    g1.loadGraph(graph1);



    vector<vector<int>> graph2 = {

            {0, 2, 0},

            {2, 0, 2},

            {0, 2, 0}};

    g2.loadGraph(graph2);



    CHECK_EQ(2 * g1,g2);

}


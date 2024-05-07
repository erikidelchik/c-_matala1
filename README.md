the Graph class,which written at Graph.hpp, contains a matrix represented by a 2d vector.
in Graph.cpp are the implementations of the Graph's class functions: loadGraph() and printGraph().

loadGraph(g) - loads a 2d matrix into the matrix local varieble at Graph's class.
printGraph(g) - prints the number of vertices and edges in the graph.


at Algorithms.hpp, there are two classes: Algorithms (which contains the algorithms) and Vertex(which represents a vertex, and contains key (distance from source vector), pi(a pointer to the predeccesor), a color, and list of neighbors).

isConnected(g) - if row and col number i are 0 returns false, else true.
shortestPath(g) - uses topological sort on a list of Vertices, then uses bellman ford on this list (bellman ford also checks if there is a negative cycle). then check and return the path from 'end' to 'start' by using the pi of each Vertex. 
isContainsCycle(g) - uses BFS on every vertex of the graph (the findCycle() func), and checks if it got to the 'start' vector along the way. if yes - returns the cycle.
isBipartite(g) - add vertex 0 to A. then add each neighbor of 0 to B. then do it for each vertex in B... and so on until we have visited all vertices. then check if there is a common vertex in both groups (A and B), 
and then check if there is an edge between each 2 vertices on both groups. if not, returns the groups.
negativeCycle(g) - for each vertex in the graph, does bellman ford (bellman ford return the first edge of a negative cycle, and if there is no negative cycle, return -1), and if it didnt return -1, find a cycle from the vertex he returned.

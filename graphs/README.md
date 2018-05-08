# Graph Algorithms

## Important Points

* Cycle Detection:- In undirected graphs, either bfs or dfs can be used to detect cycles, but in case of directed graphs only dfs can be used.
* In ford-fulkerson algorithm, bfs is preferred because it reduces the worst case complexity to O(VE^2)
* In list, allocation of memory is non-contiguous, but in case of vector, memory is alloted in contiguous manner.
* Solving Puzzles with only one solution, such as mazes can be solved using dfs 

### Problems

* __Longest Path__ from a point to all the nodes in a graph(directed)
	* Also Implemented __topological sort__ in this code (As the main idea is to topologically sort the directed graph and then assign the distance to nodes)
	* Time complexity is O(V+E)
	* [CODE](./LongestPath.cpp)

* Finding __Mother Vertex__ of a graph (It is that vertex from which we can reach every vertex in the graph)
	* In case of undirected & connected graph, every vertex is a mother vertex, In case of undirected or directed unconnected graph mother vertex doesn't exist. so problem of finding happens only in case of directed and connected graph.
	* So the idea is as it is a mother vertex, when we do topological sort it should be the first vertex(ie parent of all), to confirm whether it is mother vertex or not, check it by doing dfs starting from mother vertex.

* __Transitive closure__ of a graph( Using DFS)
	* Given a directed graph, find out if a vertex v is reachable from another vertex u for all vertex pairs (u, v) in the given graph. Here reachable mean that there is a path from vertex u to v. The reach-ability matrix is called transitive closure of a graph.
	* O(V^2) complexity if we use DFS, O(V^3) if we use idea of Floyd-Marshall algorithm

* __K-cores__ of Undirected graph
	* Given a graph, k-cores of a graph are connected components that are left after removing all vertices of the graph that have degree less than k.(Idea of solving is quite important)
	* Here we start dfs with start node as node having minimum degree
	* __Degeneracy__ of a graph is largest value k such that graph is a k-core.
	* [CODE](./k-core.cpp)

* __Count Path__ between two vertices in directed graph
	* Here it should not be cyclic because, vertices will be visited in a loop making the path to rotate in a circle which will result in an infinite number of paths.
	* Idea is to run dfs and backtrack, ie, make the vertex visit and then traverse the path, if it leads to destination then increase count and backtrack by making the vertex or node unvisited at the end of dfs.
	* [CODE](./pathcount.cpp)


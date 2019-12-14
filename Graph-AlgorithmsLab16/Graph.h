#ifndef GRAPH_H
#define GRAPH_H

#include <list>
#include <iostream>

class Graph
{
private:
	int vertices_amount;

	//pointer to an array containing adjacency lists
	std::list<int>* adj;

	void depth_first_search_recursive(int v, bool visited[]);
public:
	Graph();
	Graph(int vertices_amount);

	bool add_adge(int vertex, int neighbour);

	void depth_first_search(int vertex);
	void breadth_first_search(int vertex);

	friend std::ostream& operator<<(std::ostream& out, const Graph& graph);
};
#endif // !GRAPH_H
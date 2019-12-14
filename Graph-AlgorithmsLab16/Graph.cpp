#include "Graph.h"
#include <iostream>

void Graph::depth_first_search_recursive(int vertex, bool visited[])
{
	visited[vertex] = true;
	std::cout << vertex << "\t";

	std::list<int>::iterator i;
	for (i = adj[vertex].begin(); i != adj[vertex].end(); ++i)
		if (!visited[*i])
			depth_first_search_recursive(*i, visited);
}

Graph::Graph()
{
	this->vertices_amount = 19;	//why not?
	adj = new std::list<int>[this->vertices_amount];
}

Graph::Graph(int vertices_amount)
{
	this->vertices_amount = vertices_amount;
	adj = new std::list<int>[vertices_amount];
}

bool Graph::add_adge(int vertex, int neighbour)
{
	if (vertex >= vertices_amount || neighbour >= vertices_amount)
	{
		std::cout << "Both \'v\' and \'w\' should be less then "
				<< vertices_amount << std::endl;
		return false;
	}

	adj[vertex].push_back(neighbour);
	return true;
}

void Graph::depth_first_search(int vertex)
{
	std::cout << "Following is Depth First Traversal (starting from vertex "
		<< vertex << ")\n";

	bool* visited = new bool[vertices_amount];
	for (int i = 0; i < vertices_amount; i++)
		visited[i] = false;

	depth_first_search_recursive(vertex, visited);
	std::cout << std::endl;
}

void Graph::breadth_first_search(int vertex)
{
	std::cout << "Following is Breadth First Traversal (starting from vertex "
		<< vertex << ")\n";

	bool* visited = new bool[vertices_amount];
	for (int i = 0; i < vertices_amount; ++i)
		visited[i] = false;

	std::list<int> queue;

	visited[vertex] = true;
	queue.push_back(vertex);

	// 'i' will be used to get all adjacent vertices of a vertex
	std::list<int>::iterator i;

	while (!queue.empty())
	{
		vertex = queue.front();
		std::cout << vertex << "\t";
		queue.pop_front();

		for (i = adj[vertex].begin(); i != adj[vertex].end(); ++i)
		{
			if (!visited[*i])
			{
				visited[*i] = true;
				queue.push_back(*i);
			}
		}
	}
}

std::ostream& operator<<(std::ostream& out, const Graph& graph)
{
	for (int v = 0; v < graph.vertices_amount; ++v)
	{
		if (graph.adj[v].empty())
			continue;
		out << "\nAdjacency list of vertex "
			<< v << std::endl;
		out << v;
		for (auto x : graph.adj[v])
			out << "-> " << x;
		out << std::endl;
	}
	return out;
}
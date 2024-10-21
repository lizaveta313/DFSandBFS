#include <vector>

#pragma once

class Graph {
private:
	int nNode;
	std::vector<std::vector<int>> adjacencyList;

public:
	Graph(int v);
	Graph(const Graph& other);
	~Graph() = default;
	std::vector<std::vector<int>>& getAdjacencyList();
	void addEdge(int start, int finish);
	void display() const;
	void DFS(int startNode);
	void BFS(int startNode);
};
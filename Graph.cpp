#include "Graph.h"
#include <iostream>
#include <algorithm>
#include <vector> 
#include <stack>
#include <queue>

Graph::Graph(int v = 0) {
    nNode = v;
    adjacencyList.resize(v);
}
Graph::Graph(const Graph& other) : nNode(other.nNode), adjacencyList(other.adjacencyList) {}

void Graph::addEdge(int start, int finish) {
    adjacencyList[start].push_back(finish);
    adjacencyList[finish].push_back(start); // Неориентированный граф
}

std::vector<std::vector<int>>& Graph::getAdjacencyList() {
    return adjacencyList;
}

void Graph::DFS(int startNode) {
    std::cout << "Обход в глубину" << std::endl;

    bool* visited = new bool[nNode]; // Массив для отслеживания посещенных вершин
    std::fill(visited, visited + nNode, false); // Изначально все вершины непосещенные

    std::stack<int> stack; // Стек для хранения вершин
    stack.push(startNode); // Начальная вершина

    while (!stack.empty()) {
        int node = stack.top();
        stack.pop();

        if (!visited[node]) {
            visited[node] = true; // Помечаем как посещенную
            std::cout << node << " "; // Выводим вершину

            // Добавляем все смежные вершины в стек
            for (int adjacent : adjacencyList[node]) {
                if (!visited[adjacent]) {
                    stack.push(adjacent);
                }
            }
        }
    }
    std::cout << std::endl;
    delete[] visited; // Освобождаем память
}
void Graph::BFS(int startNode) {
    std::cout << "Обход в ширину" << std::endl;

    bool* visited = new bool[nNode]; // Массив для отслеживания посещенных вершин
    std::fill(visited, visited + nNode, false); // Изначально все вершины непосещенные
    
    std::queue<int> queue; // Очередь для хранения вершин
    visited[startNode] = true; // Помечаем начальную вершину как посещенную
    queue.push(startNode); // Добавляем ее в очередь

    while (!queue.empty()) {
        int node = queue.front();
        queue.pop();
        std::cout << node << " "; // Выводим вершину

        // Добавляем все смежные вершины в очередь
        for (int adjacent : adjacencyList[node]) {
            if (!visited[adjacent]) {
                visited[adjacent] = true; // Помечаем как посещенную
                queue.push(adjacent);
            }
        }
    }
    std::cout << std::endl;
    delete[] visited; // Освобождаем память
}

void Graph::display() const {
    for (int i = 0; i < nNode; ++i) {
        std::cout << "Node " << i << ":";
        for (int neighbor : adjacencyList[i]) {
            std::cout << " -> " << neighbor;
        }
        std::cout << std::endl;
    }
}
#include "Graph.h"
#include <iostream>
#include <cstdlib>
#include <vector>

int main()
{
    setlocale(LC_ALL, "Russian");

    int nNode; 
    std::cout << "Введите количество вершин: ";
    std::cin >> nNode;
    int nEdge;
    std::cout << "Введите количество рёбер: ";
    std::cin >> nEdge;

    Graph g(nNode);

    std::cout << "Введите через пробел пары соединенных вершин: ";
    for (int i = 0; i < nEdge; ++i) {
        int start, finish;
        std::cin >> start >> finish;
        g.addEdge(start, finish);
    }

    std::cout << "Список смежности" << std::endl;
    g.display();

    int startNode;
    std::cout << "Введите начальную вершину для обхода: ";
    std::cin >> startNode;

    g.DFS(startNode);
    g.BFS(startNode);

    return 0;
}


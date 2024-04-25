/*Shortest paths from vertex "1":
1 -> 2: (1 -> 2) = 7
1 -> 3: (1 -> 3) = 9
1 -> 4: (1 -> 3 -> 4) = 20
1 -> 5: (1 -> 3 -> 6 -> 5) = 20
1 -> 6: (1 -> 3-->6) = 11
Shortest paths from vertex "2":
2 -> 1: (2 -> 1) = 7
2 -> 3: (2 -> 3) = 10
2 -> 4: (2 -> 4) = 15
2 -> 5: (2 -> 3 -> 6 -> 5) = 22
2 -> 6: (2 -> 3 -> 6) = 12
Shortest paths from vertex "3":
3 -> 1: (3 -> 1) = 9
3 -> 2: (3 -> 2) = 10
3 -> 4: (3 -> 4) = 11
3 -> 5: (3 -> 6 -> 5) = 11
3 -> 6: (3 -> 6) = 2
Shortest paths from vertex "4":
4 -> 1: (4 -> 3 -> 1) = 20
4 -> 2: (4 -> 3 -> 2) = 21
4 -> 3: (4 -> 3) = 11
4 -> 5: (4 -> 5) = 6
4 -> 6: (4 -> 3 -> 6) = 13
Shortest paths from vertex "5":
5 -> 1: (5 -> 6 -> 3 -> 1) = 20
5 -> 2: (5 -> 6 -> 3 -> 2) = 22
5 -> 3: (5 -> 6 -> 3) = 11
5 -> 4: (5 -> 4) = 6
5 -> 6: (5 -> 6) = 9
Shortest paths from vertex "6":
6 -> 1: (6 -> 1) = 14
6 -> 2: (6 -> 3 -> 2) = 12
6 -> 3: (6 -> 3) = 2
6 -> 4: (6 -> 3 -> 4) = 13
6 -> 5: (6 -> 5) = 9*/


#include <iostream>
#include <vector>
#include <string>
#include "Graph.hpp"

void output(int shortestDistance, std::vector<std::string> &path, std::string startLabel, std::string endLabel)
{
    if (shortestDistance != std::numeric_limits<unsigned long>::max()) {
        std::cout << "Shortest distance from " << startLabel << " to " << endLabel << " is: " << shortestDistance << std::endl;
        std::cout << "Shortest path: ";
        for (const std::string& vertex : path) {
            std::cout << vertex;
            if (vertex!=endLabel) {
                std::cout << " -> ";
            }
        }
        std::cout << "\n";
    } else {
        std::cout << "No path exists from " << startLabel << " to " << endLabel << std::endl << "\n";
    }
}
int main() {
    Graph graph;
    graph.addVertex("0");
    graph.addVertex("1");
    graph.addVertex("2");
    graph.addVertex("3");
    graph.addVertex("4");
    graph.addVertex("5");
    graph.addVertex("6");
    graph.addEdge("1", "2", 7);
    graph.addEdge("1", "3", 9);
    graph.addEdge("1", "6", 14);
    graph.addEdge("2", "3", 10);
    graph.addEdge("2", "4", 15);
    graph.addEdge("3", "4", 11);
    graph.addEdge("3", "6", 2);
    graph.addEdge("4", "5", 6);
    graph.addEdge("5", "6", 9);

    std::vector<std::string> path;

    //Test for paths starting at 1 
    output(graph.shortestPath("1", "2", path), path, "1", "2");
    output(graph.shortestPath("1", "3", path), path, "1", "3");
    output(graph.shortestPath("1", "4", path), path, "1", "4");
    output(graph.shortestPath("1", "5", path), path, "1", "5");
    output(graph.shortestPath("1", "6", path), path, "1", "6");

    //Tests for paths starting at 2
    output(graph.shortestPath("2", "1", path), path, "2", "1");
    output(graph.shortestPath("2", "3", path), path, "2", "3");
    output(graph.shortestPath("2", "4", path), path, "2", "4");
    output(graph.shortestPath("4", "2", path), path, "3", "5");
    output(graph.shortestPath("2", "6", path), path, "2", "6");

    //Tests for paths starting at 3
    output(graph.shortestPath("3", "1", path), path, "3", "1");
    output(graph.shortestPath("3", "2", path), path, "3", "2");
    output(graph.shortestPath("3", "4", path), path, "3", "4");
    output(graph.shortestPath("3", "5", path), path, "3", "5");
    output(graph.shortestPath("3", "6", path), path, "3", "6");

    //Tests for paths starting at 4
    output(graph.shortestPath("4", "2", path), path, "4", "2");
    output(graph.shortestPath("4", "3", path), path, "4", "3");
    output(graph.shortestPath("4", "1", path), path, "4", "1");
    output(graph.shortestPath("4", "5", path), path, "4", "5");
    output(graph.shortestPath("4", "6", path), path, "4", "6");

    //Tests for paths starting at 5
    output(graph.shortestPath("5", "1", path), path, "5", "1");
    output(graph.shortestPath("5", "2", path), path, "5", "2");
    output(graph.shortestPath("5", "3", path), path, "5", "3");
    output(graph.shortestPath("5", "4", path), path, "5", "4");
    output(graph.shortestPath("5", "6", path), path, "5", "6");

    //Tests for paths starting at 6
    output(graph.shortestPath("6", "1", path), path, "6", "1");
    output(graph.shortestPath("6", "2", path), path, "6", "2");
    output(graph.shortestPath("6", "3", path), path, "6", "3");
    output(graph.shortestPath("6", "4", path), path, "6", "4");
    output(graph.shortestPath("6", "5", path), path, "6", "5");

    return 0;
}
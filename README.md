# Implementation of Dijkstra's Algorithm

Dijkstra's algorithm is a method for finding the shortest paths between nodes in a graph.It starts at a designated source node and explores neighboring nodes, updating the shortest path to each node as it progresses. 

We will using undirected weighted Graph ADT.


## Features

- Shortest Pathfinding: By applying the algorithm, the code provides the shortest path between nodes in a graph.
- Customizable Graph: We have included methods to add/remove verticles, edges so the user can customize the graph as their personal use.
- Simple Interface: Included edge, vertex and graphbase so its easy to implement into a bigger project. 


## Lessons Learned

While build this project, our team learned deeper about Graph ADT and the algorithm. Also, we successfully applied optimal substructure, triangle inequality and convergence to build the calculate shortest path function.

## Usage/Examples

```C++
#include <iostream>
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
int main(){
    int main() {
    //implement the graph
    Graph graph;
    graph.addVertex("1");
    graph.addVertex("2");
    graph.addVertex("3");
    graph.addVertex("4");
    graph.addEdge("1", "2", 7);
    graph.addEdge("2", "3", 10);
    graph.addEdge("2", "4", 15);
    graph.addEdge("3", "4", 11);
    // print shortest paths. As we see there are 2 ways to get to node 4 from node 1 but the algorithm will print 1->3->4
    // instead of 1->2->4.
    std::vector<std::string> path;
    output(graph.shortestPath("1", "4", path), path, "1", "4");

    return 0;
}
```


## Authors

- Sadman Sakib
- Anuj Khemka
- Khoa Le
- Marvin Guerrero-Rangel

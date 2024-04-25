#include <string>
#include "Vertex.hpp"
#include "Edge.hpp"
#include <iostream>

Vertex::Vertex(std::string input) {
    vertex_label = input;
}

Vertex::~Vertex() {
    edges.clear();
}

void Vertex::addEdge(const Edge& edge) {
    edges.push_back(edge);
}

void Vertex::removeEdge(std::string label) {
    for (int i=0;i<edges.size();i++) {
        if ((edges[i]).getFirst()==label || (edges[i]).getSecond()==label) {
            edges.erase(edges.begin()+i);
        }
    }
}
std::string Vertex::getLabel() const {
    return vertex_label;
}
std::vector<Edge> Vertex::getEdges() const {
    return edges;
}

void Vertex::getNeighbors() const {
    for (int i=0;i<edges.size();i++) {
        Edge e= edges[i];
        std::string store = getLabel();
        std::cout << store << " " << e.getLabel(store) << ": " << e.getWeight() << "\n";
    }   
}

unsigned long Vertex::getPriority() const {
    return priority;
}

void Vertex::setPriority(int p) {
    priority = p;
}

bool Vertex::in_Queue() {
    return in_queue;
}
void Vertex::setQueue(bool value) {
    in_queue=value;    
}
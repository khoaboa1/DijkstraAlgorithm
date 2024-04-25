#ifndef VERTEX_H
#define VERTEX_H

#include "Edge.hpp"
#include <vector>
#include <string>
#include <limits>

class Vertex
{
public:
    Vertex();
    ~Vertex();
    Vertex(std::string input);
    void getNeighbors() const;
    void addEdge(const Edge& edge);
    void removeEdge(std::string label);
    std::string getLabel() const;
    std::vector<Edge> getEdges() const;
    void setPriority(int p);
    unsigned long getPriority() const;
    bool in_Queue();
    void setQueue(bool value);
    void setPrevious(Vertex * prev) {
        previous = prev;
    }
    Vertex * getPrevious() {
        return previous;
    }

private:
    std::vector<Edge> edges;
    std::string vertex_label;
    unsigned long priority = std::numeric_limits<unsigned long>::max();
    bool in_queue=false;
    Vertex * previous = nullptr;
};
    
#endif
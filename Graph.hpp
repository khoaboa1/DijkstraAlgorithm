#ifndef GRAPH_H
#define GRAPH_H
#include "GraphBase.hpp"
#include "Vertex.hpp"
#include "Edge.hpp"
//#include "MinHeap.hpp"
#include <vector>
#include <string>
#include <queue>
class Graph : public GraphBase
{
public:
    Graph();
    ~Graph();
    void addVertex(std::string label);
    void removeVertex(std::string label);
    void addEdge(std::string label1, std::string label2, unsigned long weight);
    void removeEdge(std::string label1, std::string label2);
    unsigned long shortestPath(std::string startLabel, std::string endLabel, std::vector<std::string>
    &path);

private:

    struct Comp{
        bool operator()(const Vertex * a, const Vertex * b){
            return (*a).getPriority() >= (*b).getPriority();
        }
    };
    std::vector<Vertex> vertices;
    std::priority_queue<Vertex*, std::vector<Vertex*>, Comp> pq;
    struct less_than_key
    {
    inline bool operator() (const Vertex vertex1, const Vertex vertex2)
    {
        return (stoi(vertex1.getLabel()) <= stoi(vertex2.getLabel()));
    }
    };
};
    
#endif
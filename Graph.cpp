#include "Graph.hpp"
#include <string>
#include "Vertex.hpp"
#include <iostream>
#include <vector>
#include <algorithm>

Graph::Graph() {
    
}

Graph::~Graph() {

}

void Graph::addVertex(std::string label) {
    //adds the vertex to the vertices vector 
    //index must match the label
    Vertex new_vertex(label);
    vertices.push_back(new_vertex);
}

void Graph::removeVertex(std::string label) {
    //removes the vertex from the vertices vector
    for (int i=0;i<vertices.size();i++) {
        if (vertices[i].getLabel()==label) {
            vertices.erase(vertices.begin() + i);
        }
    }
}

void Graph::addEdge(std::string label1, std::string label2, unsigned long weight) {
    //if the vertices vector is out of order, sort it
    if (vertices.size()-1!=stoi(vertices[vertices.size()-1].getLabel())) {
        std::sort(vertices.begin(), vertices.end(), less_than_key());
    }
    Edge new_edge(label1, label2, weight);
    //find vertices with label1 and label2
    Vertex* vertex1 = nullptr;
    Vertex* vertex2 = nullptr;

    //confirms that the vertices exist in the array
    for (int i=0;i<vertices.size();i++) {
        if (vertices[i].getLabel() == label1) {
            vertex1 = &vertices[i];
        }
        if (vertices[i].getLabel() == label2) {
            vertex2 = &vertices[i];
        }
    }
    // if both vertices exist, add the edge to their edge list 
    if (vertex1 && vertex2) {
        vertex1->addEdge(new_edge);
        vertex2->addEdge(new_edge);
    }
    //create an Edge class, and in the edge class have the first node and have the second node it's connected to
    //add it to the sub lists for the edges vector

}

//search through the edge lists for each label, and if the edge in question is connected to both label 1 and label 2, then remove it
void Graph::removeEdge(std::string label1, std::string label2) {
    for (int i=0;i<vertices.size();i++) {
        if (vertices[i].getLabel()==label1) {
            vertices[i].removeEdge(label2);
        }
        else if (vertices[i].getLabel()==label2) {
            vertices[i].removeEdge(label1);
        }
    }   
}

unsigned long Graph::shortestPath(std::string startLabel, std::string endLabel, std::vector<std::string> &path) {
    path.clear();
    while (!pq.empty()) {
        Vertex * current = pq.top();
        pq.pop();
    }
   //declares start and end pointers
    Vertex * start;
    Vertex * end;
    //adds vertices to the priority queue 
    for (int i=0;i<vertices.size();i++) {
        if (vertices[i].getLabel()==startLabel) {
            start = &vertices[i];
            //if it's the start vertex, it gets added with a priority of 0 and configure in_queue to true
            (*start).setPriority(0);
            (*start).setPrevious(nullptr);
            pq.push(start);
            (*start).setQueue(true);
        }
        //if it's not the start vertex, add it with max priority and configure in_queue to true
        else {
            vertices[i].setQueue(true);
            vertices[i].setPriority((std::numeric_limits<unsigned long>::max()));
            pq.push(&vertices[i]);
        }
        //find the end vertex
        if (vertices[i].getLabel()==endLabel) {
            end = &vertices[i];
        }
    }
    //run while there are still elements in the priority queue
    while (!pq.empty()) {
        //get the topmost element
        Vertex * current = pq.top();
        pq.pop();
        (*current).setQueue(false);
        if ((*current).getLabel()==endLabel) {
            break;
        }
        //configure in_queue to false
        //get the edges for the vertex
        std::vector edges = (*current).getEdges();
        if (edges.size()==0) {
            break;
        }
        //loop through the vector edges 
        for (int i =0;i<edges.size();i++) {
            //neighbor is equal to the vertex on the opposite end of the edge
            Vertex * neighbor = &(vertices[stoi(edges[i].getLabel((*current).getLabel()))]);
            //if the neighbor is in the queue, set the priority to whichever is smaller between the current priority and the current's priority + edge weight
            if ((*neighbor).in_Queue()) {
                int priority = std::min((*neighbor).getPriority(), (*current).getPriority()+edges[i].getWeight());
                if (priority<(*neighbor).getPriority()) {
                    (*neighbor).setPriority(priority);
                    (*neighbor).setPrevious(current);
                    //re-add the vertex pointer to the priority queue if the priority becomes smaller
                    pq.push(neighbor);}
            }
        }
    }
    //go backwards to find the path
    Vertex * cycle = end;
    while (cycle!=nullptr) {
        path.push_back((*cycle).getLabel());
        cycle = (*cycle).getPrevious();
    }
    std::reverse(path.begin(), path.end());
    //return the priority of the end to get the shortest path from start to the end
    return (*end).getPriority();
}



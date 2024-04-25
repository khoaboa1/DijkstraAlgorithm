#ifndef EDGE_H
#define EDGE_H

#include <vector>
#include <string>
class Edge
{
public:
    Edge();
    ~Edge();
    Edge (std::string first, std::string second, int weight);
    std::string getFirst() const;
    std::string getSecond() const;
    std::string getEdges();
    int getWeight();
    std::string getLabel(std::string current);


private:
    std::string firstLabel;
    std::string secondLabel;
    int edge_weight;
};
    
#endif
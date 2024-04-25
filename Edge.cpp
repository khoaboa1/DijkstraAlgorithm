#include "Edge.hpp"
#include <string>

Edge::Edge(std::string first, std::string second, int weight) {
    firstLabel = first;
    secondLabel=second;
    edge_weight = weight;
}

Edge::~Edge() {

}

std::string Edge::getFirst() const {
    return firstLabel;
}

std::string Edge::getSecond() const {
    return secondLabel;
}

int Edge::getWeight() {
    return edge_weight;
}

std::string Edge::getLabel(std::string current) {
    if (firstLabel==current) {
        return secondLabel;
    }
    else {
        return firstLabel;
    }
}
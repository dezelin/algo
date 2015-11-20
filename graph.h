#ifndef GRAPH_H
#define GRAPH_H

#include <vector>

class Graph
{
public:
    Graph();

private:
    std::vector<std::vector<int>> _edges;
};

#endif // GRAPH_H

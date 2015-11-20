#ifndef GRAPH_H
#define GRAPH_H

#include <vector>

class Graph
{
public:
    typedef std::vector<int> AdjacencyList;
    typedef std::vector<AdjacencyList> VerticesList;

public:
    Graph(int num);

    void Add(int v, const AdjacencyList& adj);
    const AdjacencyList& Adj(int v) const;

private:
    VerticesList _vertices;
};

#endif // GRAPH_H

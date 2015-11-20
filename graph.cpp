#include "graph.h"

#include <assert.h>

Graph::Graph(int num)
    : _vertices(num)
{

}

void Graph::Add(int v, const Graph::AdjacencyList &adj)
{
    assert(v >= 0);
    assert(v < (int)_vertices.size());
    _vertices[v] = adj;
}

const Graph::AdjacencyList &Graph::Adj(int v) const
{
    assert(v >= 0);
    assert(v < (int)_vertices.size());
    return _vertices[v];
}


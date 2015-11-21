#ifndef GRAPH_H
#define GRAPH_H

#include <vector>

class WeightedGraph
{
public:
    typedef std::pair<int, double> Edge;
    typedef std::vector<int> VerticesList;
    typedef std::vector<Edge> AdjacencyList;
    typedef std::vector<AdjacencyList> EdgesList;

public:
    WeightedGraph(const EdgesList& edges);

    void Add(int v, const AdjacencyList& adj);
    const AdjacencyList& Adj(int v) const;

    VerticesList DfsPreOrder(int src) const;
    VerticesList DfsPreOrderRec(int src) const;
    VerticesList DijkstraShortP(int src, int dest) const;

private:
    VerticesList DfsPreOrderRecHelper(int src, std::vector<bool>& color) const;

private:
    EdgesList _vertices;
};

#endif // GRAPH_H

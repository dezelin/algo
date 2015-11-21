#include "weightedgraph.h"

#include <assert.h>
#include <algorithm>
#include <limits>
#include <queue>
#include <set>
#include <stack>

WeightedGraph::WeightedGraph(const EdgesList &edges)
    : _vertices(edges)
{

}

void WeightedGraph::Add(int v, const WeightedGraph::AdjacencyList &adj)
{
    assert(v >= 0);
    assert(v < (int)_vertices.size());
    _vertices[v] = adj;
}

const WeightedGraph::AdjacencyList &WeightedGraph::Adj(int v) const
{
    assert(v >= 0);
    assert(v < (int)_vertices.size());
    return _vertices[v];
}

WeightedGraph::VerticesList WeightedGraph::DfsPreOrder(int src) const
{
    std::size_t size = _vertices.size();
    std::vector<bool> color(size);

    VerticesList list;

    std::stack<int> ps;
    ps.push(src);

    while(!ps.empty()) {
        int u = ps.top();
        ps.pop();

        if (color[u])
            continue;

        color[u] = true;
        list.push_back(u);
        for(const Edge& e : Adj(u)) {
            ps.push(e.first);
        }
    }

    return list;
}

WeightedGraph::VerticesList WeightedGraph::DfsPreOrderRec(int src) const
{
    std::size_t size = _vertices.size();
    std::vector<bool> color(size);
    return DfsPreOrderRecHelper(src, color);
}

WeightedGraph::VerticesList WeightedGraph::DfsPreOrderRecHelper(int src, std::vector<bool> &color) const
{
    VerticesList list;
    list.push_back(src);
    color[src] = true;

    for(const Edge& e : Adj(src)) {
        if (color[e.first])
            continue;

        color[e.first] = true;
        VerticesList t = DfsPreOrderRecHelper(e.first, color);
        list.insert(list.end(), t.begin(), t.end());
    }

    return list;
}

WeightedGraph::VerticesList WeightedGraph::DijkstraShortP(int src, int dest) const
{
    std::size_t size = _vertices.size();
    std::vector<double> dist(size, std::numeric_limits<double>::max());
    std::vector<bool> color(size);
    VerticesList pred(size, -1);

    dist[src] = 0.0;
    std::priority_queue<int> pq;
    pq.push(src);

    while(!pq.empty()) {
        int u = pq.top();
        pq.pop();

        if (color[u])
            continue;

        // Mark as visited
        color[u] = true;
        for(const Edge& e : Adj(u)) {
            if (dist[e.first] > dist[u] + e.second) {
                dist[e.first] = dist[u] + e.second;
                pq.push(e.first);
                pred[e.first] = u;
            }
        }
    }

    VerticesList shortp;
    for( ; dest != -1 ; dest = pred[dest])
        shortp.push_back(dest);

    std::reverse(shortp.begin(), shortp.end());
    return shortp;
}


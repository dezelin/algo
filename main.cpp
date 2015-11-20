
#include "weightedgraph.h"

#include <iterator>
#include <iostream>

using namespace std;

int main()
{
    WeightedGraph::AdjacencyList adj0 = {
        { 5, 14 }, { 1, 7 }, { 2, 9 }, { 6, 14 }
    };

    WeightedGraph::AdjacencyList adj1 = {
        { 0, 7 }
    };

    WeightedGraph::AdjacencyList adj2 = {
        { 0, 9 }
    };

    WeightedGraph::AdjacencyList adj3 = {
        { 5, 6 }, { 4, 15 }
    };

    WeightedGraph::AdjacencyList adj4 = {
        { 3, 6 }, { 5, 9 }, { 6, 9 }
    };

    WeightedGraph::AdjacencyList adj5 = {
        { 4, 14 }, { 3, 9 }
    };

    WeightedGraph::AdjacencyList adj6 = {
        { 0, 14 }, { 4, 9 }
    };

    WeightedGraph g({ adj0, adj1, adj2, adj3, adj4, adj5, adj6 });
    WeightedGraph::VerticesList path = g.DijkstraShortP(0, 4);

    std::cout << "Path : ";
    std::copy(path.begin(), path.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    WeightedGraph::VerticesList list = g.DfsPreOrder(0);

    std::cout << "Dfs list preorder : ";
    std::copy(list.begin(), list.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    list = g.DfsPreOrderRec(0);

    std::cout << "Dfs list preorder rec: ";
    std::copy(list.begin(), list.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    return 0;
}

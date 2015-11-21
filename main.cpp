
#include "sort.h"
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

    int randomList[] = { 12, 6, 1, 4, 5, 8, 0 };
    std::vector<int> sortList(std::begin(randomList), std::end(randomList));
    Sort::Quick(sortList);

    std::cout << "Quicksort list: ";
    std::copy(sortList.begin(), sortList.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    sortList = std::vector<int>(std::begin(randomList), std::end(randomList));
    Sort::Insertion(sortList);

    std::cout << "Insertion list: ";
    std::copy(sortList.begin(), sortList.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    sortList = std::vector<int>(std::begin(randomList), std::end(randomList));
    Sort::Selection(sortList);

    std::cout << "Selection list: ";
    std::copy(sortList.begin(), sortList.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    return 0;
}


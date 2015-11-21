#ifndef SORT_H
#define SORT_H

#include <vector>

class Sort
{
public:
    Sort();

    static void Insertion(std::vector<int>& v);
    static void Quick(std::vector<int>& v);

private:
    static int Partition(std::vector<int>& v, int l, int r);
    static void QuickHelper(std::vector<int>& v, int l, int r);
};

#endif // SORT_H

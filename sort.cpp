#include "sort.h"

Sort::Sort()
{

}

void Sort::Insertion(std::vector<int> &v)
{
    for(int i = 1; i < (int)v.size(); ++i) {
        int j = i;
        while(j > 0 && v[j - 1] > v[j]) {
            std::swap(v[j - 1], v[j]);
            --j;
        }
    }
}

void Sort::Quick(std::vector<int> &v)
{
    QuickHelper(v, 0, v.size() - 1);
}

int Sort::Partition(std::vector<int> &v, int l, int r)
{
    int pivot = v[l];
    while(r > l) {
        while(v[l] < pivot) ++l;
        while(v[r] > pivot) --r;
        if (r > l) std::swap(v[l++], v[r--]);
    }

    return r;
}

void Sort::QuickHelper(std::vector<int>& v, int l, int r)
{
    if (r <= l)
        return;

    int p = Partition(v, l, r);
    QuickHelper(v, 0, p);
    QuickHelper(v, p + 1, r);
}


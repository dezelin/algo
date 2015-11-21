#include "sort.h"

Sort::Sort()
{

}

void Sort::Selection(std::vector<int> &v)
{
    for(int i = 0; i < (int)v.size() - 1; ++i) {
        int min = i;
        for(int j = i + 1; j < (int)v.size(); ++j) {
            if (v[min] > v[j]) min = j;
        }

        if (min != i)
            std::swap(v[min], v[i]);
    }
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


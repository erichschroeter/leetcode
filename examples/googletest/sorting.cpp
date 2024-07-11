#include "sorting.h"

using namespace std;

void quick_sort(vector<int>& v) {
    if (v.size() < 2) {
        return;
    }

    // Choose an arbitrary pivot point in the middle and remove it.
    int pivot_index = v.size() / 2;
    int pivot = v.at(pivot_index);
    v.erase(v.begin() + pivot_index);

    // Partition the remaining items into lists lesser or equal, and greater than the pivot.
    vector<int> lesser_or_equal;
    vector<int> greater;
    for (int i = 0; i < v.size(); ++i) {
        if (v.at(i) <= pivot) {
            lesser_or_equal.push_back(v.at(i));
        } else {
            greater.push_back(v.at(i));
        }
    }

    quick_sort(lesser_or_equal);
    quick_sort(greater);
    v.clear();
    v.insert(v.end(), lesser_or_equal.begin(), lesser_or_equal.end());
    v.push_back(pivot);
    v.insert(v.end(), greater.begin(), greater.end());
}

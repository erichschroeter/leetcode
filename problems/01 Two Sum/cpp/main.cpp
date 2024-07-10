#include <iostream>
#include <vector>

using namespace std;

template < class T >
std::ostream& operator << (std::ostream& os, const std::vector<T>& v) 
{
    os << "[";
    bool is_first = true;
    for (typename std::vector<T>::const_iterator ii = v.begin(); ii != v.end(); ++ii)
    {
        if (is_first) {
            os << *ii;
            is_first = false;
        } else {
            os << " " << *ii;
        }
    }
    os << "]";
    return os;
}


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

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        if (nums.size() < 2) {
            throw runtime_error("need at least 2 input nums");
        }
        quick_sort(nums);
        // cout << "twoSum: " << nums << endl;
        vector<int> indices;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < nums.size() - 1; ++j) {
                int sum = nums[i] + nums[j];
                if (sum == target) {
                    indices.push_back(i);
                    indices.push_back(j);
                    return indices;
                }
            }
        }
        return indices;
    }
};

int main() {
    Solution solution;
    vector<int> example_1_nums({2,7,11,15});
    int example_1_expected = 9;
    auto result_1 = solution.twoSum(example_1_nums, example_1_expected);
    if (result_1.size() == 2 && result_1[0] == 0 && result_1[1] == 1) {
        cout << "Example 1: PASS" << endl;
    } else {
        cout << "Example 1: FAIL" << endl;
    }

    vector<int> example_2_nums({3,2,4});
    int example_2_expected = 6;
    auto result_2 = solution.twoSum(example_2_nums, example_2_expected);
    if (result_2.size() == 2 && (example_2_nums[result_2[0]] + example_2_nums[result_2[1]]) == example_2_expected) {
        cout << "Example 2: PASS" << endl;
    } else {
        if (result_2.size() > 1) {
            cout << "Example 2: FAIL  expected [1,2] but got [" << result_2[0] << ',' << result_2[1] << "]" << endl;
        } else {
            cout << "Example 2: FAIL  expected [1,2] but result had " << result_2.size() << " items" << endl;
        }
    }

    vector<int> example_3_nums({3,3});
    int example_3_expected = 6;
    auto result_3 = solution.twoSum(example_3_nums, example_3_expected);
    if (result_3.size() == 2 && (example_3_nums[result_3[0]] + example_3_nums[result_3[1]]) == example_3_expected) {
        cout << "Example 3: PASS" << endl;
    } else {
        if (result_3.size() > 1) {
            cout << "Example 3: FAIL  expected [0,1] but got [" << result_3[0] << ',' << result_3[1] << "]" << endl;
        } else {
            cout << "Example 3: FAIL  expected [0,1] but result had " << result_3.size() << " items" << endl;
        }
    }
    return 0;
}
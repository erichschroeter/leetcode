#include <gtest/gtest.h>
#include "sorting.h"

using namespace std;

TEST(TestQuicksortSuite, ListOfOne) {
    vector<int> actual({2});
    vector<int> expected({2});
    quick_sort(actual);
    ASSERT_EQ(expected, actual);
}

TEST(TestQuicksortSuite, FirstTwoOutOfOrder) {
    vector<int> actual({7,2});
    vector<int> expected({2,7});
    quick_sort(actual);
    ASSERT_EQ(expected, actual);
}

TEST(TestQuicksortSuite, LastTwoOutOfOrder) {
    vector<int> actual({2,7,15,11});
    vector<int> expected({2,7,11,15});
    quick_sort(actual);
    ASSERT_EQ(expected, actual);
}

TEST(TestQuicksortSuite, FirstAndLastOutOfOrder) {
    vector<int> actual({15,7,11,2});
    vector<int> expected({2,7,11,15});
    quick_sort(actual);
    ASSERT_EQ(expected, actual);
}

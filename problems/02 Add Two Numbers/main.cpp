#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (nullptr == l1) {
            throw runtime_error("l1 must not be null");
        }
        if (nullptr == l2) {
            throw runtime_error("l2 must not be null");
        }
        return l1;
    }
};

int main() {
    Solution sol;
    ListNode l1_ex1(2, new ListNode(4, new ListNode(3)));
    ListNode l2_ex1(5, new ListNode(6, new ListNode(4)));
    auto r1 = sol.addTwoNumbers(&l1_ex1, &l2_ex1);
    if (r1->val == 7 && r1->next->val == 0 && r1->next->next->val == 8) {
        cout << "Example 1: PASS" << endl;
    } else {
        cout << "Example 1: FAIL    " << r1->val << r1->next->val << r1->next->next->val << endl;
    }

    ListNode l1_ex2(2, new ListNode(4, new ListNode(3)));
    ListNode l2_ex2(5, new ListNode(6, new ListNode(4)));
    auto r2 = sol.addTwoNumbers(&l1_ex2, &l2_ex2);
    if (r2->val == 7 && r2->next->val == 0 && r2->next->next->val == 8) {
        cout << "Example 2: PASS" << endl;
    } else {
        cout << "Example 2: FAIL    " << r2->val << r2->next->val << r2->next->next->val << endl;
    }

    ListNode l1_ex3(2, new ListNode(4, new ListNode(3)));
    ListNode l2_ex3(5, new ListNode(6, new ListNode(4)));
    auto r3 = sol.addTwoNumbers(&l1_ex3, &l2_ex3);
    if (r3->val == 7 && r3->next->val == 0 && r3->next->next->val == 8) {
        cout << "Example 3: PASS" << endl;
    } else {
        cout << "Example 3: FAIL    " << r3->val << r3->next->val << r3->next->next->val << endl;
    }
    return 0;
}

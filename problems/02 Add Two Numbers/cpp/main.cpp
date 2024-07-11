#include <iostream>
#include <string>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

string to_string(ListNode* n) {
    string output = "[";
    ListNode * cursor = n;
    bool after_first = false;
    while (cursor != nullptr) {
        if (after_first) {
            output += ",";
        }
        after_first = true;
        output += to_string(cursor->val);
        cursor = cursor->next;
    }
    output += "]";
    return output;
}

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
        // cout << to_string(l1) << " + " << to_string(l2) << endl;
        int carryover = 0;
        int sum = 0;
        ListNode * cursor_l1 = l1;
        ListNode * cursor_l2 = l2;
        ListNode * answer = nullptr;
        ListNode * answer_begin = nullptr;
        // Keep iterating if more digits exist in either list
        while (cursor_l1 != nullptr || cursor_l2 != nullptr) {
            if (cursor_l1 != nullptr && cursor_l2 != nullptr) {
                sum = cursor_l1->val + cursor_l2->val + carryover;
                if (sum > 9) {
                    sum = sum % 10;
                    carryover = 1;
                } else {
                    carryover = 0;
                }
                // cout << "(a) + " << to_string(sum) << endl;
            } else if (cursor_l1 != nullptr) {
                sum = cursor_l1->val + carryover;
                if (sum > 9) {
                    sum = sum % 10;
                    carryover = 1;
                } else {
                    carryover = 0;
                }
                // cout << "(b) + " << to_string(sum) << endl;
            } else if (cursor_l2 != nullptr) {
                sum = cursor_l2->val + carryover;
                if (sum > 9) {
                    sum = sum % 10;
                    carryover = 1;
                } else {
                    carryover = 0;
                }
                // cout << "(c) + " << to_string(sum) << endl;
            }
            if (answer == nullptr) {
                // cout << "new answer " << to_string(sum) << endl;
                answer = new ListNode(sum);
                answer_begin = answer;
            } else {
                // cout << "old answer " << to_string(sum) << endl;
                answer->next = new ListNode(sum);
                answer = answer->next;
            }
            if (cursor_l1 != nullptr) {
                cursor_l1 = cursor_l1->next;
            }
            if (cursor_l2 != nullptr) {
                cursor_l2 = cursor_l2->next;
            }
        }
        if (carryover > 0) {
            answer->next = new ListNode(carryover);
            answer = answer->next;
        }
        return answer_begin;
    }
};

int main() {
    Solution sol;
    ListNode l1_ex1(2, new ListNode(4, new ListNode(3)));
    ListNode l2_ex1(5, new ListNode(6, new ListNode(4)));
    auto r1 = sol.addTwoNumbers(&l1_ex1, &l2_ex1);
    // cout << "r1: " << to_string(r1) << endl;
    if (r1->val == 7 && r1->next->val == 0 && r1->next->next->val == 8) {
        cout << "Example 1: PASS" << endl;
    } else {
        cout << "Example 1: FAIL    " << to_string(r1) << " expected [7,0,8]" << endl;
    }

    ListNode l1_ex2(0);
    ListNode l2_ex2(0);
    auto r2 = sol.addTwoNumbers(&l1_ex2, &l2_ex2);
    // cout << "r2: " << to_string(r2) << endl;
    if (r2->val == 0) {
        cout << "Example 2: PASS" << endl;
    } else {
        cout << "Example 2: FAIL    " << to_string(r2) << " expected [0]" << endl;
    }

    ListNode l1_ex3(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9)))))));
    ListNode l2_ex3(9, new ListNode(9, new ListNode(9, new ListNode(9))));
    auto r3 = sol.addTwoNumbers(&l1_ex3, &l2_ex3);
    // cout << "r3: " << to_string(r3) << endl;
    if (r3->val == 8 &&
        r3->next->val == 9 &&
        r3->next->next->val == 9 &&
        r3->next->next->next->val == 9 &&
        r3->next->next->next->next->val == 0 &&
        r3->next->next->next->next->next->val == 0 &&
        r3->next->next->next->next->next->next->val == 0 &&
        r3->next->next->next->next->next->next->next->val == 1) {
        cout << "Example 3: PASS" << endl;
    } else {
        cout << "Example 3: FAIL    " << to_string(r3) << " expected [8,9,9,9,0,0,0,1]" << endl;
    }
    return 0;
}

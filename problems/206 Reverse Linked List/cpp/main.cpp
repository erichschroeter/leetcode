#include <iostream>
#include <string>
#include <vector>

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

struct Node {
    ListNode *prev;
    ListNode *next;
    Node() : prev(nullptr), next(nullptr) {}
    Node(ListNode *prev, ListNode *next) : prev(prev), next(next) {}
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
    ListNode* reverseList(ListNode* head) {
        if (nullptr == head) {
            return head;
        }
        ListNode * cur = head;
        vector<ListNode*> ordered;
        while (cur != nullptr) {
            ordered.push_back(cur);
            cur = cur->next;
        }
        int i = 0;
        vector<ListNode*>::iterator iter = ordered.end();
        for (int i = ordered.size()-1; i != -1; --i) {
            if (i > 0) {
                ordered[i]->next = ordered[i-1];
                // cout << "  " << to_string(ordered[i]->val) << " to " << to_string(ordered[i-1]->val) << endl;
            } else {
                // cout << "  " << to_string(ordered[i]->val) << " to null" << endl;
                ordered[i]->next = nullptr;
            }
        }
        return ordered[ordered.size()-1];
    }
};

int main() {
    Solution sol;
    ListNode ex1(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    auto r1 = sol.reverseList(&ex1);
    // cout << "r1: " << to_string(r1) << endl;
    if (r1->val == 5 &&
        r1->next->val == 4 &&
        r1->next->next->val == 3 &&
        r1->next->next->next->val == 2 &&
        r1->next->next->next->next->val == 1) {
        cout << "Example 1: PASS" << endl;
    } else {
        cout << "Example 1: FAIL    " << to_string(r1) << " expected [5,4,3,2,1]" << endl;
    }

    ListNode ex2(1, new ListNode(2));
    auto r2 = sol.reverseList(&ex2);
    // cout << "r2: " << to_string(r2) << endl;
    if (r2->val == 2 && r2->next->val == 1) {
        cout << "Example 2: PASS" << endl;
    } else {
        cout << "Example 2: FAIL    " << to_string(r2) << " expected [2,1]" << endl;
    }

    ListNode ex3(0);
    auto r3 = sol.reverseList(&ex3);
    // cout << "r3: " << to_string(r3) << endl;
    if (r3->val == 0) {
        cout << "Example 3: PASS" << endl;
    } else {
        cout << "Example 3: FAIL    " << to_string(r3) << " expected [0]" << endl;
    }
    return 0;
}

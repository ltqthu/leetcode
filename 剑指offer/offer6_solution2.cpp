#include <iostream>
#include <stack>
#include <vector>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        ListNode* pMove = head;
        if (pMove == nullptr) {
            return {};
        }
        vector<int> vec = reversePrint(pMove->next);
        vec.push_back(pMove->val);
        return vec;
    }
};

int main() {
    ListNode* pHead = new ListNode(1);
    pHead->next = new ListNode(3);
    pHead->next->next = new ListNode(2);

    Solution s = Solution();
    vector<int> vec = s.reversePrint(pHead);
    for (int i = 0; i <vec.size(); ++i) {
        cout << vec[i] << " ";
    }
    cout << endl;
    return 0;
}
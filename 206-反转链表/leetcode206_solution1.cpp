/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//  1->2->3->4->5->NULL
//

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) return head;
        ListNode *pFast = head, *pSlow = nullptr;
        ListNode* pTemp = pFast->next;

        while (pFast != nullptr) {
            pTemp = pFast->next;
            pFast->next = pSlow;
            pSlow = pFast;
            pFast = pTemp;
        }
        return pSlow;
    }
};

int main() {
    Solution solution = Solution();
    ListNode* pHead = new ListNode(1);
    ListNode* pNode2 = new ListNode(2);
    ListNode* pNode3 = new ListNode(3);
    ListNode* pNode4 = new ListNode(4);
    ListNode* pNode5 = new ListNode(5);
    ListNode* pNode6 = new ListNode(6);
    pHead->next = pNode2;
    pNode2->next = pNode3;
    pNode3->next = pNode4;
    pNode4->next = pNode5;
    pNode5->next = pNode6;

    ListNode* pRes = solution.reverseList(pHead);
    while (pRes != nullptr) {
        cout << pRes->val << " ";
        pRes = pRes->next;
    }
    cout << endl;

    return 0;
}
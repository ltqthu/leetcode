#include "../leetcode.h"

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) return head;

        ListNode* pSlow = head;
        ListNode* pFast = head->next;

        while (pFast != nullptr) {
            if (pFast->val == pSlow->val) {
                pFast = pFast->next;
            } else {
                pSlow->next = pFast;
                pSlow = pSlow->next;
                pFast = pFast->next;
            }
        }
        pSlow->next = nullptr;
        return head;
    }
};

int main() {
    Solution solution = Solution();
    ListNode* pHead = new ListNode(1);
    ListNode* pNode2 = new ListNode(1);
    ListNode* pNode3 = new ListNode(2);
    ListNode* pNode4 = new ListNode(3);
    ListNode* pNode5 = new ListNode(4);
    ListNode* pNode6 = new ListNode(4);
    pHead->next = pNode2;
    pNode2->next = pNode3;
    pNode3->next = pNode4;
    pNode4->next = pNode5;
    pNode5->next = pNode6;

    ListNode* pRes = solution.deleteDuplicates(pHead);
    while (pRes != nullptr) {
        cout << pRes->val << " ";
        pRes = pRes->next;
    }
    cout << endl;

    return 0;
}
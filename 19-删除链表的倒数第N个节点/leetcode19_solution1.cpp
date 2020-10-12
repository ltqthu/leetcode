#include "../leetcode.h"

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (n < 0 || head == nullptr) return nullptr;
        ListNode* pDummy = new ListNode(-1);
        pDummy->next = head;
        ListNode* pSlow = pDummy;
        ListNode* pFast = pDummy->next;
        for (int i = 0; i < n; ++i) {
            pFast = pFast->next;
        }
        while (pFast != nullptr) {
            pFast = pFast->next;
            pSlow = pSlow->next;
        }
        pSlow->next = pSlow->next->next;
        return pDummy->next;
    }
};

int main() {
    Solution solution = Solution();
    ListNode* pHead = InitList(vector<int>{1, 2, 3, 4, 5});
    PrintList(pHead, "before remove: ");
    pHead = solution.removeNthFromEnd(pHead, 2);
    PrintList(pHead, "after remove: ");

    return 0;
}

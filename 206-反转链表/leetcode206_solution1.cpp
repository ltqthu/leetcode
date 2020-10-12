#include "../leetcode.h"

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
    ListNode* pHead = InitList(vector<int>{1, 2, 3, 4, 5, 6});

    ListNode* pRes = solution.reverseList(pHead);
    PrintList(pRes);

    return 0;
}
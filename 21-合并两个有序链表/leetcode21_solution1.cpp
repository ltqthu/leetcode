#include "../leetcode.h"

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;
        ListNode* pDummy = new ListNode(-1);
        ListNode* pMove = pDummy;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                pMove->next = l1;
                l1 = l1->next;
            } else {
                pMove->next = l2;
                l2 = l2->next;
            }
            pMove = pMove->next;
        }
        pMove->next = l1 == nullptr ? l2 : l1;
        return pDummy->next;
    }
};

int main() {
    Solution solution = Solution();
    ListNode* l1 = InitList(vector<int>{1, 2, 4});
    ListNode* l2 = InitList(vector<int>{1, 3, 4});
    ListNode* pHead = solution.mergeTwoLists(l1, l2);
    PrintList(pHead);

    return 0;
}

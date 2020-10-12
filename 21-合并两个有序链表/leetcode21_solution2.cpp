#include "../leetcode.h"

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;
        if (l1->val <= l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
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

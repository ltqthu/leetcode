#include "../leetcode.h"

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* pRes = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return pRes;
    }
};

int main() {
    Solution solution = Solution();
    ListNode* pHead = InitList(vector<int>{1, 2, 3, 4, 5, 6});

    ListNode* pRes = solution.reverseList(pHead);
    PrintList(pRes);

    return 0;
}
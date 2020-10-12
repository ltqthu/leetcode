#include "../leetcode.h"

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *pHead = new ListNode();  // 头节点
        ListNode *pMove = pHead;           // 移动节点

        int t2 = 0;
        while (l1 != nullptr || l2 != nullptr) {
            // 如果节点为空
            int l1_val = (l1 == nullptr) ? 0 : l1->val;
            int l2_val = (l2 == nullptr) ? 0 : l2->val;

            int t1 = l1_val + l2_val + t2;

            t2 = t1 / 10;
            t1 = t1 % 10;

            pMove->val = t1;

            if (l1 != nullptr) {
                l1 = l1->next;
            }

            if (l2 != nullptr) {
                l2 = l2->next;
            }

            // 如果有一个链表的节点都不为空，则创建新节点。新节点不一定要有数
            // 如果t2===1（前面节点的计算有进位），则创建新节点，并且新节点的数为1
            if ((l1 != nullptr || l2 != nullptr) || t2 == 1) {
                pMove->next = new ListNode(t2);
                pMove = pMove->next;
            }
        }
        return pHead;
    }
};

void Test1() {
    cout << "Test1():" << endl;
    ListNode *l1 = InitList(vector<int>{2, 4, 3});
    PrintList(l1, "l1: ");

    ListNode *l2 = InitList(vector<int>{5, 6, 4});
    PrintList(l2, "l2: ");

    Solution s = Solution();
    ListNode *list = s.addTwoNumbers(l1, l2);
    PrintList(list, "sum: ");
}

void Test2() {
    cout << "Test2():" << endl;
    ListNode *l1 = CreateList(vector<int>{5});
    PrintList(l1, "l1: ");

    ListNode *l2 = InitList(vector<int>{5});
    PrintList(l2, "l2: ");

    Solution s = Solution();
    ListNode *list = s.addTwoNumbers(l1, l2);
    PrintList(list, "sum: ");
}

void Test3() {
    cout << "Test3():" << endl;

    ListNode *l1 = InitList(vector<int>{1, 8});
    PrintList(l1, "l1: ");

    ListNode *l2 = InitList(vector<int>{0});
    PrintList(l2, "l2: ");

    Solution s = Solution();
    ListNode *list = s.addTwoNumbers(l1, l2);
    PrintList(list, "sum: ");
}

int main() {
    Test1();
    Test2();
    Test3();
    return 0;
}
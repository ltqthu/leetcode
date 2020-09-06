#include <iostream>
using namespace std;

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

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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

void Print(ListNode *pHead) {
    ListNode *pMove = pHead;
    while (pMove != nullptr) {
        cout << pMove->val << " ";
        pMove = pMove->next;
    }
    cout << endl;
}

void Test1() {
    cout << "Test1():" << endl;
    ListNode l1 = ListNode(2);
    ListNode l1_2 = ListNode(4);
    ListNode l1_3 = ListNode(3);
    l1.next = &l1_2;
    l1.next->next = &l1_3;
    Print(&l1);

    ListNode l2 = ListNode(5);
    ListNode l2_2 = ListNode(6);
    ListNode l2_3 = ListNode(4);
    l2.next = &l2_2;
    l2.next->next = &l2_3;
    Print(&l2);

    Solution s = Solution();
    ListNode *list = s.addTwoNumbers(&l1, &l2);
    Print(list);
}

void Test2() {
    cout << "Test2():" << endl;

    ListNode l1 = ListNode(5);
    Print(&l1);

    ListNode l2 = ListNode(5);
    Print(&l2);

    Solution s = Solution();
    ListNode *list = s.addTwoNumbers(&l1, &l2);
    Print(list);
}

void Test3() {
    cout << "Test3():" << endl;
    ListNode l1 = ListNode(1);
    ListNode l1_2 = ListNode(8);
    l1.next = &l1_2;
    Print(&l1);

    ListNode l2 = ListNode(0);
    Print(&l2);

    Solution s = Solution();
    ListNode *list = s.addTwoNumbers(&l1, &l2);
    Print(list);
}

int main() {
    Test1();
    Test2();
    Test3();

    return 0;
}

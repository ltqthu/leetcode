#ifndef __LEETCODE__H__
#define __LEETCODE__H__

#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// 打印容器内容
template <typename T>
inline void PrintContainer(const T& coll, const string& optstr = "") {
    cout << optstr;
    for (const auto& elem : coll) {
        cout << elem << " ";
    }
    cout << endl;
}

// 链表结构体
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// 通过vector初始化链表
template <typename T>
ListNode* InitList(const vector<T>& v) {
    if (v.size() == 0) return nullptr;
    ListNode* pDummy = new ListNode(-1);
    ListNode* pMove = pDummy;
    for (const auto& elem : v) {
        ListNode* pTemp = new ListNode(elem);
        pMove->next = pTemp;
        pMove = pMove->next;
    }
    return pDummy->next;
}

// 通过vector初始化链表
template <typename T>
ListNode* CreateList(const vector<T>& v) {
    return InitList<T>(v);
    // return nullptr;
}
// using CreateList = ListNode* InitList<T>(const vector<T>&);

// 打印链表
void PrintList(ListNode* pHead, const string& optstr = "") {
    cout << optstr;
    while (pHead) {
        cout << pHead->val << " ";
        pHead = pHead->next;
    }
    cout << endl;
}

// 销毁链表
void DestoryList(ListNode* pHead) {
    if (pHead == nullptr) return;
    ListNode* pNext = pHead->next;
    while (pNext != NULL) {
        delete pHead;
        pHead = pNext;
        pNext = pHead->next;
    };

    delete pHead;
}

#endif  // __LEETCODE__H__
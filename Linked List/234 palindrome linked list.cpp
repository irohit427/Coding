#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

typedef stack<int> Stack;
bool isPalindrome(ListNode* head) {
    Stack stk;
    ListNode* l = head;
    while(l) {
        stk.push(l->val);
        l = l->next;
    }
    while(head) {
        if (head->val != stk.top())
            return false;
        stk.pop();
        head = head->next;
    }
    return true;
}
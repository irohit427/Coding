#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int getDecimalValue(ListNode* head) {
    int num = 0, len = 0;
    ListNode* pHead = head;
    while(pHead) {
        len++;
        pHead = pHead ->next;
    }
    len--;
    while(head) {
        num += head->val * pow(2, len--);
        head = head->next;
    }
    return num;      
}
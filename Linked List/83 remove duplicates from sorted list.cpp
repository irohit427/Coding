#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* deleteDuplicates(ListNode* head) {
    
    ListNode *pHead = head;
    while(pHead) {
        while (pHead && pHead->next && pHead->val == pHead->next->val) {
            ListNode* temp = pHead->next;
            pHead->next = pHead->next->next;
            delete temp;
        }
        pHead = pHead->next;
    }
    return head;
}
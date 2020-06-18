#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    int len = 0, relDist;
    ListNode *pHead = head;
    while(pHead) {
        len++;
        pHead = pHead->next;
    }
    if (len == n) return head->next;

    relDist = len - n;
    ListNode *curr = head, *prev;
    
    while(relDist--) {
        prev = curr;
        curr = curr->next;
    }        

    ListNode* next = curr->next;
    prev->next = next;
    return head;
}
#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* l = new ListNode(0);
    ListNode* ans = l;
    while(l1 && l2) {
        if (l1 < l2) {
            l->next = l1;
            l1 = l1->next;
            l = l->next;
        } else {
            l->next = l2;
            l2 = l2->next;
            l = l->next;
        }
    }

    while(l1) {
        l->next = l1;
        l1 = l1->next;
        l = l->next;
    }

    while(l2) {
        l->next = l2;
        l2 = l2->next;
        l = l->next;
    }
    return ans->next;
}
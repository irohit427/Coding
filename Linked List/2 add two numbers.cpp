#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *result = new ListNode(0);
    ListNode* dummy = result; 
    int carry = 0, sum;
    while(l1 != nullptr && l2 != nullptr) {
        sum = l1 -> val + l2 -> val + carry;
        carry = sum / 10;
        ListNode *n = new ListNode(sum % 10);
        l1 = l1->next;
        l2 = l2->next;
        result->next = n;
        result = result->next;
    } 
    while(l1 != nullptr) {
        sum = l1->val + carry;
        carry = sum / 10;
        l1 = l1->next;
        ListNode *n = new ListNode(sum % 10);
        result->next = n;
        result = result->next;
    }
    while(l2 != nullptr) {
        sum = l2->val + carry;
        carry = sum / 10;
        l2 = l2->next;
        ListNode *n = new ListNode(sum % 10);
        result->next = n;
        result = result->next;
    }
    if (carry) {
        ListNode* n = new ListNode(carry);
        result->next = n;
    }
    return dummy->next;
}
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
    ListNode *cur = head, *prev = NULL, *start = NULL;
    while(cur){
        ListNode *temp = cur;
        int fl = 0;
        while(temp->next && temp->val == temp->next->val){
            fl = 1;
            temp = temp->next;
        }
        if(fl){
            cur = temp->next;
            continue;
        }
        if(!start)
            start = cur;
        if(!prev)
            prev = start;
        else{
            prev->next = cur;
            prev = prev->next;
        }
        cur = cur->next;        
    }
    if(prev)
        prev->next = NULL;
    return start;    
}
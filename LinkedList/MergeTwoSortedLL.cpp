#include <bits/stdc++.h>
#include"LinkedList.h"

using namespace std;


/*
You are given two sorted linked lists.
Merge them into one sorted linked list.

Example
List1: 1 → 3 → 5
List2: 2 → 4 → 6

Output: 1 → 2 → 3 → 4 → 5 → 6

*/

class Solution{
public:
    ListNode* mergeTwolist(ListNode* l1, ListNode* l2){
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while(l1 && l2){
            if(l1->val < l2->val){
                tail->next = l1;
                l1 = l1->next;
            }
            else{
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        tail->next = (l1) ? l1 : l2;
        /*
        if (l1 != nullptr) {
            tail->next = l1;
        } else {
            tail->next = l2;
        }
        */
        return dummy.next;
    }

};

int main(){
    
    return 0;
}
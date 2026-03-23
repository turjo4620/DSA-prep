#include <bits/stdc++.h>
#include"LinkedList.h"

using namespace std;

/*
Given a linked list, remove the N-th node from the end and return the head of the list.
Example
Input:  1 → 2 → 3 → 4 → 5, n = 2
Output: 1 → 2 → 3 → 5
2nd node from the end is 4, so we remove it

*/

ListNode* removeNthFromEnd(ListNode* head, int n){
    ListNode dummy(0);
    dummy.next = head;

    ListNode* slow = &dummy;
    ListNode* fast = &dummy;


    //Moving fast pointer n + 1 steps
    for(int i = 0; i <= n; i++){
        fast = fast->next;
    }

    while(fast != nullptr){
        fast = fast->next;
        slow = slow->next;
    }

    slow->next = slow->next->next;

    return dummy.next;
}

int main(){
    
    return 0;
}
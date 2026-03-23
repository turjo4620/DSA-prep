#include <bits/stdc++.h>
#include"LinkedList.h"

using namespace std;


/*
Given the head of a linked list, return the middle node.

👉 If there are two middle nodes, return the second one.

Input:  1 → 2 → 3 → 4 → 5
Output: 3

Input:  1 → 2 → 3 → 4 → 5 → 6
Output: 4   (second middle) 



Concept: slow fast pointer approach use korbo

slow -> moves 1 step and fast -> moves 2 step 

jokhon fast reaches at the end, slow will be at the middle


*/

class solution{
public:

    ListNode* middleNode(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;

        // Don't forget to write fast->next != nullptr

        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
};

int main(){
    
    return 0;
}
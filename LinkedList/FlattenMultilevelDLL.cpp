#include <bits/stdc++.h>

using namespace std;
#include"LinkedList.h"

/*
🧠 Problem Statement

You are given a multilevel doubly linked list:

Each node has:
val
next
prev
optional child → another doubly linked list
Flatten the list so all nodes appear in a single-level doubly linked list
Child pointers should be set to NULL in the result


📌 Example
1 - 2 - 3 - 4 - 5 - 6
        |
        7 - 8 - 9 - 10
            |
            11 - 12

Flattened:

1 - 2 - 3 - 7 - 8 - 11 - 12 - 9 - 10 - 4 - 5 - 6

*/

class Solution {
public:
    ListNode* flatten(ListNode* head) {
        if(head == NULL){
            return NULL;
        }
        ListNode* curr = head;
        while(curr!= NULL){
            if(curr->child != NULL){
                ListNode* temp = curr->next;
                ListNode* new_child = flatten(curr->child);
                curr->next = new_child;
                new_child->prev = curr;
                curr->child = NULL;

                ListNode* last = new_child;
                while(last->next != NULL){
                    last = last->next;
                }
                last->next = temp;
                if(temp != NULL){
                    temp->prev = last;
                }

            }
        curr = curr->next;
        }
        return head;
    }
};


int main(){
    
    return 0;
}
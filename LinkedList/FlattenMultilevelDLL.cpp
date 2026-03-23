#include <bits/stdc++.h>

using namespace std;
#include"LinkedList.h"

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
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
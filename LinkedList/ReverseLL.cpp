#include <bits/stdc++.h>
#include"LinkedList.h"
using namespace std;

// Given the head of a singly linked list, reverse the list and return the new head.

// Input:  1 → 2 → 3 → 4 → NULL
// Output: 4 → 3 → 2 → 1 → NULL


// Iterative solution

class solution{
    public:
        ListNode* reverseList(ListNode* head){
            ListNode* prev = NULL;
            ListNode* curr = head;


            //Always store the next node first and maintain proper order
            //We are just reversing the connection here

            while(curr != NULL){
                ListNode* next_node = curr->next; // Current er next hobe next_node
                curr->next = prev; // Current er next take previous e point kore dile connection ulte jabe
                prev = curr; // previous ta hobe ekhoner current ta
                curr = next_node; // current take next node baniye dibo
            }
            return prev;
        }


        //Recursive solution
        ListNode* reverselist_recurstion(ListNode* head){
            if(head == nullptr || head->next == nullptr){
                return head;
            }
            ListNode* newHead = reverselist_recurstion(head->next);

            head->next->next = head;
            // 2->3->4 dhoro emon ase ekhon ami chaitechi (head ekhon 2) 2 porer je 3 ase shey jate 2 ke point kore mane 2<-3 emon hoy and 2->3 ei connection ta bhenge jay...!!!
            head->next = nullptr;

            return newHead;
        }
};


int main(){
    
    return 0;
}
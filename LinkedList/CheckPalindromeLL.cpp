#include <bits/stdc++.h>
#include"LinkedList.h"
using namespace std;

/*
Given the head of a singly linked list, check if it is a palindrome (reads the same forward and backward).

Input:  1 → 2 → 3 → 2 → 1
Output: true

Input:  1 → 2 → 2 → 3
Output: false

*/


/*
Concept:

1. find the middle
2. reverse the half
3. compare two halves

*/


class solution{
public:
    bool isPalindrome(ListNode* head){
        if(!head || !head->next) return true;

        //1. Finding the middle
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }

        //2.Reverse the second half

        ListNode* prev = nullptr;
        ListNode* curr = slow->next;

        while(curr){
            ListNode* next_node = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next_node;
        }

        //3. Compare

        ListNode* first = head;
        ListNode* second = prev;

        bool palindrome = true;
        while(second){
            if(first->val != second->val){
                palindrome = false;
                break;
            }
            first = first->next;
            second = second->next;
        }

        //Optional step -> restoring the list

        curr = prev;
        prev = nullptr;

        while(curr){
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        slow->next = prev;

        return palindrome;

    }
};
int main(){
    
    return 0;
}
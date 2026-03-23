#include <bits/stdc++.h>
#include"LinkedList.h"
using namespace std;

/*
Given the head of a linked list, rotate the list to the right by k places.
Example
Input: 1 → 2 → 3 → 4 → 5, k = 2
Output: 4 → 5 → 1 → 2 → 3
Last 2 nodes move to the front
*/

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        // Step 1: Find length and tail
        ListNode* tail = head;
        int length = 1;
        while (tail->next) {
            tail = tail->next;
            length++;
        }

        // Step 2: Make circular
        tail->next = head;

        // Step 3: Find new tail
        k = k % length;
        int stepsToNewTail = length - k - 1;
        ListNode* newTail = head;
        for (int i = 0; i < stepsToNewTail; i++) {
            newTail = newTail->next;
        }

        // Step 4: New head
        ListNode* newHead = newTail->next;

        // Step 5: Break circle
        newTail->next = nullptr;

        return newHead;
    }
};

int main(){
    
    return 0;
}
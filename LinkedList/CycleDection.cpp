#include <bits/stdc++.h>
#include"LinkedList.h"

using namespace std;


/*

Given the head of a linked list, determine if the list has a cycle.

👉 A cycle means:

1 → 2 → 3 → 4 → 5
          ↑     ↓
          ←  ←  ←

Concept: slow fast pointer approach

jodi cycle thake ekta shomoy eshe slow ar fast meet korbe otherwise fast null e chole jabe

*/

class solution{
public:
    bool hasCycle(ListNode* head){
        if(head == nullptr)return false;

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast){
                return true;
            }
        }
        return false;
    }
};

int main(){
    
    return 0;
}
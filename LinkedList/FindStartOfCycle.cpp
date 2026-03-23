#include <bits/stdc++.h>
#include"LinkedList.h"

using namespace std;

/*
Problem Statement

Given a linked list with a cycle, return the node where the cycle begins.

If no cycle → return NULL

📌 Example
1 → 2 → 3 → 4 → 5
          ↑     ↓
          ← ← ←

Output = node 3 (cycle starts here)

*/


/*
Ei problem er duita phase 
1. Cycle dection
2. move one pointer to head and then again loop chalabo, pointer duita oikhanei meet korbe jekhane cycle start hoisilo
*/

class Solution{
public:
    ListNode* detectCycleStart(ListNode* head){
        if(head == nullptr) return nullptr;

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast) break;
        }

        if(fast == nullptr || fast->next == nullptr){
            return nullptr;
        }

        fast = head;
        while(fast != slow){
            slow = slow->next;
            fast = fast->next;
        }

        return fast;
    }
};
int main(){
    
    return 0;
}
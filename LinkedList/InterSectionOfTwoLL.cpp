#include <bits/stdc++.h>
#include"LinkedList.h"
using namespace std;

/*
Given the heads of two singly linked lists, find the node at which the two lists intersect.

If they do not intersect → return NULL

List A: 1 → 2 → 3 
                         ↘
                          6 → 7
                         ↗
List B:       4 → 5
Output: Node with value 6

Easy concept:

    use two pointer p1 and p2.
    Traverse each list
        when p1 reaches end, move to head of list 2
        when p2 reaches end, move to head of list 1

        if they meet ->intersection node 
        both reach null
        ->no intersection

*/

class solution{
public:
    ListNode* getIntersection(ListNode* head1, ListNode* head2){
        if(!head1 || !head2) return nullptr;

        ListNode* p1 = head1;
        ListNode* p2 = head2;

        while(p1 != p2){
            p1 = (p1) ? p1->next : head2;
            // dekho p1 jodi null hoye jay (null) -> false mane head2 te chole jabe || same for the second one
            p2 = (p2) ? p2->next : head1;
        }
        return p1;
    }
};

/*
Both pointers travel the same total distance:
lenA + lenB = lenB + lenA
So if there is an intersection, they meet after at most 2 passes
*/


int main(){
    
    return 0;
}
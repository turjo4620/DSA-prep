struct ListNode {
    int val;
    ListNode* next;
    ListNode* child;
    ListNode* prev;

    // Constructor 1
    ListNode() {
        val = 0;
        next = nullptr;
    }

    // Constructor 2
    ListNode(int x) {
        val = x;
        next = nullptr;
    }

    // Constructor 3
    ListNode(int x, ListNode* nextNode) {
        val = x;
        next = nextNode;
    }
};
#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* slow = head;

        // Move fast n steps ahead
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }

        // If fast is null, we are removing the head node
        if (!fast) return head->next;

        // Move both pointers until fast reaches the end
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }

        // Remove the nth node from end
        slow->next = slow->next->next;

        return head;
    }
};

// Optional: Helper functions for testing
void printList(ListNode* head) {
    while (head) {
        std::cout << head->val << " -> ";
        head = head->next;
    }
    std::cout << "nullptr\n";
}

// Example usage
int main() {
    // Create list: 1->2->3->4->5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution sol;
    head = sol.removeNthFromEnd(head, 2); // Removes 4

    printList(head);

    return 0;
}

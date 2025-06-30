#include <iostream>
using namespace std;

// Definition for singly-linked list
class ListNode {
public:
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to detect cycle in a linked list
bool hasCycle(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return true;
        }
    }
    return false;
}

// Main function to test the hasCycle function
int main() {
    // Create nodes
    ListNode *node1 = new ListNode(3);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(0);
    ListNode *node4 = new ListNode(-4);

    // Connect nodes: 3 -> 2 -> 0 -> -4
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;

    // Introduce a cycle: -4 -> 2 (cycle exists)
    node4->next = node2;

    if (hasCycle(node1)) {
        cout << "Cycle detected!" << endl;
    } else {
        cout << "No cycle detected." << endl;
    }

    // Optional: cleanup (in real tests, careful with cycles!)
    // To test without a cycle, comment out: node4->next = node2;

    return 0;
}

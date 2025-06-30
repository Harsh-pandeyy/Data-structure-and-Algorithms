#include <iostream>
using namespace std;

class ListNode {
public:
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *detectCycle(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            slow = head;
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow; // Cycle start
        }
    }

    return nullptr; // No cycle
}

int main() {
    // Create nodes
    ListNode *node1 = new ListNode(3);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(0);
    ListNode *node4 = new ListNode(-4);

    // Create cycle: 3 -> 2 -> 0 -> -4 -> 2 (cycle starts at node2)
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node2;

    ListNode *cycleStart = detectCycle(node1);
    if (cycleStart != nullptr) {
        cout << "Cycle detected at node with value: " << cycleStart->val << endl;
    } else {
        cout << "No cycle detected." << endl;
    }

    return 0;
}

#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* oddEvenList(ListNode* head) {
    if (head == nullptr)
        return nullptr;

    ListNode* o = nullptr;     // For connecting odd index nodes
    ListNode* es = nullptr;    // Head of even index nodes
    ListNode* ee = nullptr;    // For connecting even index nodes
    ListNode* curr = head;     // For traversing the original list
    int count = 1;             // Position tracker

    while (curr != nullptr) {
        if (count & 1) { // Odd index
            if (o == nullptr) {
                o = curr;
                head = o; // Maintain new head pointing to the first odd node
            } else {
                o->next = curr;
                o = o->next;
            }
        } else { // Even index
            if (es == nullptr) {
                es = curr;
                ee = curr;
            } else {
                ee->next = curr;
                ee = ee->next;
            }
        }
        count++;
        curr = curr->next;
    }

    if (o != nullptr)
        o->next = es;

    if (ee != nullptr)
        ee->next = nullptr;

    return head;
}

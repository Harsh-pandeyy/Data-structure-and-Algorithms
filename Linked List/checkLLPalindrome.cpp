class ListNode {
public:
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* reverseList(ListNode* head) {
        if(head==nullptr || head->next==nullptr){
            return head;
        }
        ListNode*newhead=reverseList(head->next);
        ListNode*front=head->next;
        front->next=head;
        head->next=nullptr;
        return newhead;
    }
    bool isPalindrome(ListNode* head) {
        if(head==nullptr || head->next==nullptr)return true;
        ListNode*slow=head;
        ListNode*fast=head;
        while(fast->next!=nullptr && fast->next->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode*head2=reverseList(slow->next);
        ListNode*first=head;
        ListNode*second=head2;
        while(second){
            if(first->val==second->val){
                first=first->next;
                second=second->next;
            }
            else{
            reverseList(head2);
            return 0;
            }
            
        }
        reverseList(head2);
        return 1;
        }
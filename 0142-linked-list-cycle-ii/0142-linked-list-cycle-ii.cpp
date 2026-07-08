class Solution {
public:
    ListNode* detectCycle(ListNode* head) {

        if(!head || !head->next) return nullptr;
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                break;
            }
            
        }slow = head;
        if(fast == head) return slow;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next;

            if (slow == fast)
                return slow;
        }
        return nullptr;
    }
};

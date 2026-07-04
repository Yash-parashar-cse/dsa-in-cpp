class Solution {
public:

    ListNode* reverseHalf(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = curr->next;

        while(curr){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr= next;
        }
        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* secondHalf = reverseHalf(slow);
        ListNode* t1 = head;
        ListNode* t2 = secondHalf;

        while(t1 && t2){
            if(t1->val != t2->val) return false;
            t1=t1->next;
            t2=t2->next;
        }
        return true;
    }
};
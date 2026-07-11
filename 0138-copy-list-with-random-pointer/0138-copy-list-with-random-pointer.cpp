class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;
    
        Node* temp = head;

        // creating a list in which both the original and copied nodes are
        // interleaved..
        while (temp != nullptr) {
            Node* next = temp->next;
            Node* copy = new Node(temp->val);
            temp->next = copy;
            copy->next = next;

            temp = next;
        }

        // setting the random pointers..
        temp = head;
        while (temp != nullptr) {
            if (temp->random) {
                temp->next->random = temp->random->next;
            } else {
                temp->next->random = nullptr;
            }

            temp = temp->next->next;
        }
        // Detaching the required list..
        
        temp = head;
        Node* copyHead = temp->next;
        while(temp != nullptr){
            Node* copy = temp->next;
            temp->next = copy->next;

            if(copy->next!=nullptr){
                copy->next = copy->next->next;
        }
        temp = temp->next;
        

        }return copyHead;

    }
};
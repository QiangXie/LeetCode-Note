class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr){
            return head;
        }      
        ListNode * p = head;
        while(p != nullptr){
            if(p->next != nullptr && p->val == p->next->val){
                p->next = p->next->next;
            }
            else if(p->next == nullptr){
                return head;
            }
            else{
                p = p->next; 
            }
        }
        return head;
    }
};
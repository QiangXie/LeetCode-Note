class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* i, *j;
        i = head;
        j = head;
        int k;
        for(k = 0; k < n && j->next != nullptr; k++){
            j = j->next;
        }
        if(k != n){
            return head->next;
        }
        while(j->next != nullptr){
            i = i->next;
            j = j->next;
        }
        i->next = i->next->next;
        return head;
        
    }
};
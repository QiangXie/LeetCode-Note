class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == nullptr){
            return false;
        }   
        ListNode * i, *j;
        i = head;
        j = head->next;
        while(i != j){
            if(j != nullptr && j->next != nullptr){
                j = j->next->next;
            }
            else{
                return false;
            }
            i = i->next;
        }
        return true;
    }
};
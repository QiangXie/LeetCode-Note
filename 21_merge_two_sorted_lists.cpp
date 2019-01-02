class Solution {
    public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* ans = nullptr;
        if(l1 == nullptr){
            return l2;
        }
        if(l2 == nullptr){
            return l1;
        }
        ListNode* temp1, *temp2, *temp3;
        temp1 = l1;
        temp2 = l2;
        temp3 = nullptr;
        if(l1->val < l2->val){
            ans = l1;
            l1 = l1->next;
        }
        else{
            ans = l2;
            l2 = l2->next;
        }
        temp3 = ans;
        while(l1 != nullptr && l2 != nullptr){
            if(l1->val < l2->val){
                temp3->next = l1;
                temp3 = l1;
                l1 = l1->next;
            }
            else{
                temp3->next = l2;
                temp3 = l2;
                l2 = l2->next;
            }
        }
        if(l1 == nullptr){
            temp3->next = l2;
        }
        else{
            temp3->next = l1;
        }
        return ans;
    }
};
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode * head_p = new ListNode(0);
        head_p->next = head;
        ListNode * p = head_p;
        while(p->next != nullptr && p->next->next != nullptr){
            if(p->next->val == p->next->next->val){
                int temp = p->next->val;
                ListNode * p_not_same = p;
                while(p_not_same->next != nullptr && p_not_same->next->val == temp){
                    p_not_same = p_not_same->next;
                }
                if(p_not_same->next == nullptr){
                    p->next = nullptr;
                    return head_p->next;
                }
                else{
                    p->next = p_not_same->next;
                }
            }
            else{
                p = p->next;
            }
        }
        return head_p->next;
    }
};
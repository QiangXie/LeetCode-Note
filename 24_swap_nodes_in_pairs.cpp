class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* a, *b, *c, *d;
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        a = head;
        b = a->next;
        head = b;
        c = b->next;
        a->next = c;
        b->next = a;
        if(c == nullptr || c->next == nullptr){
            return head;
        }
        d = a;
        while(true){
            a->next = c;
            b->next = a;
            d->next = b;
            d = a;
            if(c == nullptr || c->next == nullptr){
                return head;
            }
            else{
                a = c;
                b = a->next;
                c = b->next;
            }
        }
        
    }
};
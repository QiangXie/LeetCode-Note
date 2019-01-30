class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == nullptr || headB == nullptr){
            return NULL;
        }
        ListNode * A, *B;
        A = headA;
        B = headB;
        int flagA = 0;
        int flagB = 0;
        while(A != B){
            if(A->next == nullptr){
                if(!flagA){
                    A = headB;
                    flagA = 1;
                }
                else{
                    A = A->next;
                }
                
            }
            else{
                A = A->next;
            }
            if(B->next == nullptr){
                if(!flagB){
                    B = headA;
                    flagB = 1;
                }
                else{
                    B = B->next;
                }
            }
            else{
                B = B->next; 
            }
        }
        if(A != nullptr){
            return A;
        }
        else{
            return NULL;
        }
    }
};
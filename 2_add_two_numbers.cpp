class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = l1;
        ListNode* indx1 = l1;
        ListNode* indx2 = l2; 
        int carry = 0;
        if(indx2 == nullptr){
            return ans;
        }
        while(true){
            indx1->val += carry + indx2->val;
            carry = 0;
            if(indx1->val >= 10){
                carry = 1;
                indx1->val %= 10;
            }
            if(indx1->next == nullptr || indx2->next == nullptr){
                break;
            }
            indx1 = indx1->next;
            indx2 = indx2->next;
        }
        if(indx1->next == nullptr && indx2->next == nullptr){
            if(carry){
                indx1->next = new ListNode(1);
                return ans;
            }
            else{
                return ans;
            }
        }
        else{
            if(indx1->next == nullptr){
                while(true){
                    indx2 = indx2->next;
                    if(indx2 == nullptr){
                        break;
                    }
                    indx1->next = new ListNode(indx2->val + carry);
                    carry = 0;
                    indx1 = indx1->next;
                    if(indx1->val >= 10){
                        carry = 1;
                        indx1->val %= 10;  
                    }
                }
                if(carry){
                    indx1->next = new ListNode(1);
                    return ans;
                }
                else{
                    return ans;
                }
            }
            else{
               while(true){
                    if(indx1->next == nullptr){
                        break;
                    }
                    indx1 = indx1->next;
                    indx1->val += carry;
                    carry = 0;
                    if(indx1->val >= 10){
                        carry = 1;
                        indx1->val %= 10;
                    }
               } 
               if(carry){
                   indx1->next = new ListNode(1);
               } 
               return ans; 
            }
        }
    }
};
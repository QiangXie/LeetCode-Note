class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode * i1 = node;
        ListNode * i2 = node->next;
        while(true){
            i1->val = i2->val;
            if(i2->next == nullptr){
                i1->next = nullptr;
                break;
            }
            i1 = i1->next;
            i2 = i2->next;
        }
    }
};
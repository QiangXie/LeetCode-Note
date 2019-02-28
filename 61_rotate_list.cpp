class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr){
            return head;
        }
        ListNode * p = head;
        vector<ListNode*> temp;
        while(p != nullptr){
            temp.push_back(p);
            p = p->next;
        }
        int num = k % temp.size();
        if(num == 0){
            return head;
        }
        else{
            temp[temp.size() - 1 - num]->next = nullptr;
            temp[temp.size() - 1]->next = head;
            head = temp[temp.size() - num];
        }
        return head;
    }
};
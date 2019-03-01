class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr || k == 0 || k == 1){
            return head;
        }   
        vector<ListNode*> temp;
        while(head != nullptr){
            temp.push_back(head);
            head = head->next;
        }
        if(temp.size() < k){
            return temp[0];
        }
        if(k == temp.size()){
            for(int i = temp.size() - 1; i >= 1; --i){
                temp[i]->next = temp[i-1];
            }
            temp[0]->next = nullptr;
            return temp[temp.size()-1];
        }
        int left_num = temp.size()%k;
        ListNode * last_head;
        if(left_num){
            last_head = temp[temp.size() - left_num];
        }
        else{
            last_head = nullptr;
        }
        int group_num = temp.size()/k;
        for(int i = 0; i < temp.size()/k; ++i){
            for(int j = temp.size()-k*i-left_num-1; j >= temp.size()-k*(i+1)-left_num; --j){
                if(j != temp.size()-k*(i+1)-left_num){
                    temp[j]->next = temp[j-1];
                } 
                else{
                    temp[j]->next = last_head;
                    last_head = temp[temp.size()-k*i-left_num-1];
                    if(i == group_num - 1){
                        return last_head;
                    }
                }
            }
        }
        return last_head;
    }
};
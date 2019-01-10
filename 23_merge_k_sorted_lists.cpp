class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode * ans = nullptr;
        ListNode * p;
        int init_index;
        int temp = INT_MAX;
        bool not_all_null_flag = false;
        for(int i = 0; i < lists.size(); ++i){
            if(lists[i] != nullptr){
                if(lists[i]->val < temp){
                    not_all_null_flag = true;
                    temp = lists[i]->val;
                    init_index = i;
                }
            }
        }
        if(not_all_null_flag){
            ans = lists[init_index];
            lists[init_index] = ans->next;
            ans->next = nullptr;
            p = ans;
        }
        else{
            return ans;
        }
        do{
            temp = INT_MAX;
            not_all_null_flag = false;
            for(int i = 0; i < lists.size(); ++i){
                if(lists[i] != nullptr){
                    not_all_null_flag = true;
                    if(lists[i]->val < temp){
                        temp = lists[i]->val;
                        init_index = i;
                    }
                }
            }
            if(not_all_null_flag){
                p->next = lists[init_index];
                p = p->next;
                lists[init_index] = lists[init_index]->next;
            }
        }
        while(not_all_null_flag);
        return ans;
    }
};
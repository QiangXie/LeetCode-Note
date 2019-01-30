class Solution {
public:
    vector<int> charCounter(string s){
        vector<int> counter(26, 0);
        for(int i = 0; i < s.size(); ++i){
            counter[static_cast<int>(s[i] - 'a')] += 1;
        }
        return counter;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> temp_ans;
        for(int i = 0; i < strs.size(); ++i){
            vector<int> temp_counter = charCounter(strs[i]);
            if(temp_ans.count(temp_counter) == 0){
                vector<string> temp;
                temp_ans[temp_counter] = temp;
                temp_ans[temp_counter].push_back(strs[i]);
            }
            else{
                temp_ans[temp_counter].push_back(strs[i]);
            }
        }
        vector<vector<string>> ans;
        for(auto i = temp_ans.begin(); i != temp_ans.end(); ++i){
            ans.push_back(i->second);
        }
        return ans;
        
    }
};
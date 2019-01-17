class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        if (s.empty() || words.empty()){
            return ans;
        }
        int n = words.size();
        int m = words[0].size();
        unordered_map<string, int> map1;
        for(auto &a : words){
            ++map1[a];   
        }
        for(int i = 0; i <= (int)s.size() - n*m; ++i) {
            unordered_map<string, int> map2;
            int j = 0; 
            for (j = 0; j < n; ++j) {
                string t = s.substr(i + j * m, m);
                if (map1.find(t) == map1.end()){
                    break;   
                }
                ++map2[t];
                if (map2[t] > map1[t]){
                    break;    
                }
            }
            if (j == n){
                ans.push_back(i);   
            }
        }
        return ans;
    }
};
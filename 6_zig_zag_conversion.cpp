class Solution {
public:
    string convert(string s, int numRows) {
        if(s.size() <= numRows){
            return s;
        }
        if(numRows == 1){
            return s;
        }
        vector<string> temp_str(numRows, "");
        for(int i = 0; i < s.size(); ++i){
            int loc = i % (numRows*2-2);   
            if(loc < numRows){
                temp_str[loc] += s[i];
            }
            else{
                loc = numRows*2 - 2 - loc;
                temp_str[loc] += s[i];
            }
        }
        string ans = "";
        for(int i = 0; i < temp_str.size(); ++i){
           ans += temp_str[i];
        }
        return ans; 
    }
};
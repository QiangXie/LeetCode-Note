class Solution {
public:
    string multiply(string num1, string num2) {
        vector<string> temps;
        if(num1.size() == 0 || num2.size() == 0 || num1 == "0" || num2 == "0"){
            return "0";
        }
        for(int i = num2.size() - 1; i >= 0; --i){
            string temp = "";
            int carry = 0;     
            for(int j = num1.size() - 1; j >= 0; --j){
                int temp_product = static_cast<int>(num2[i] - '0') * static_cast<int>(num1[j] - '0') + carry;
                temp = static_cast<char>(temp_product % 10 + '0') + temp;
                carry = temp_product / 10;
            }
            temp = static_cast<char>(carry + '0') + temp;
            for(int j = 0; j < num2.size() - 1 -i; ++j){
                temp = temp + '0';
            }
            if(temp.size() != num1.size() + num2.size()){
                int temp_size = temp.size();
                for(int j = 0; j < num1.size() + num2.size() - temp_size; ++j){
                    temp = "0" + temp;
                }    
            }
            temps.push_back(temp);
        }
        int carry = 0;
        string ans = "";
        for(int i = num1.size() + num2.size() -1; i >=0; --i){
            int temp_sum = 0;
            for(int j = 0; j < temps.size(); ++j){
                if(temps[j].size() > i){
                    temp_sum += temps[j][i] - '0';
                }
            }
            temp_sum += carry;
            ans = static_cast<char>(temp_sum % 10 + '0') + ans;
            carry = temp_sum / 10;
        }
        while(ans.front() == '0'){
            ans.erase(ans.begin());
        }
        return ans;
    }
};
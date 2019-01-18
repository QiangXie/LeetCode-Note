class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        for(int i = digits.size() - 1; i >= 0; --i){
            int sum = carry + digits[i];
            carry = sum / 10;
            digits[i] = sum % 10;
        }
        if(carry == 0){
            return digits;
        }
        else{
            digits.insert(digits.begin(), 1);
            return digits;
        }
    }
};
class Solution {
public:
string addBinary(string a, string b) {
	if(a.size() < b.size()){
		string temp = a;
		a = b;
		b = temp;
	}
	if(b.size() == 0){
		return a;
	}
	int carry = 0;
	int sum = 0;
	string ans = "";
	for(int i = 0; i < a.size(); i++){
   		if(i < b.size()){
   			sum = a[a.size()-i-1] - '0' + b[b.size()-i-1] - '0' + carry;
   			carry = sum / 2;
   			ans = static_cast<char>(sum%2 + '0') + ans;
   		}
   		else{
   			sum = a[a.size()-i-1] - '0' + carry;
   			carry = sum / 2;
   			ans = static_cast<char>(sum%2 + '0') + ans;
   		} 
	}
	if(carry){
		ans = static_cast<char>(carry+'0') + ans;
	}
	return ans;
}
};
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(),digits.end());
        int carry=1;
        for(int i=0;i<digits.size();i++){
            digits[i]+=carry;
            if(digits[i] >= 10){
                digits[i]%=10;
                carry=1;
            }else{
                carry=0;
            }
        }
        if(carry){
            digits.push_back(carry);
        }
        reverse(digits.begin(),digits.end());
        return digits;
    }
};

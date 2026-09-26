class Solution {
public:
    int romanToInt(string s) {
        map<char,int> mp={
            {'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}
        };
        int decimalValue=0;
        for(int i=0;i<s.length()-1;i++){
            if(mp[s[i]]>=mp[s[i+1]]){
                decimalValue+=mp[s[i]];
            }else{
                decimalValue-=mp[s[i]];
            }
        }
        decimalValue+=mp[s[s.length()-1]];
        return decimalValue;
    }
};

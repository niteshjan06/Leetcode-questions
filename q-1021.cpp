class Solution {
public:
    string removeOuterParentheses(string s) {
        int count=0;
        string str="";
        for(int i=0;i<s.length();i++){
            if(s[i]==')'){
                count--;
            }
            if(count>0){
                str+=s[i];
            }
            if(s[i]=='('){
                count++;
            }
        }
        return str;
    }
};

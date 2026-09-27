class Solution {
public:
    int myAtoi(string s) {
        long long result=0;
        int sign=1;
        int flag=1;
        for(int i=0;i<s.length();i++){
            if(s[i]==' ' && flag){
                continue;
            }
            if(s[i]=='-' && flag){
                sign=-1;
                flag=0;
            }else if(s[i]=='+' && flag){
                flag=0;
            }else if(isdigit(s[i])){
                result*=10;
                result+=s[i]-'0';
                flag=0;

                if(sign==1 && result>INT_MAX){
                    return INT_MAX;
                }
                if(sign==-1 && result>INT_MAX){
                    return INT_MIN;
                }
            }else{
                break;
            }
        }
        result*=sign;
        return result;
    }
};

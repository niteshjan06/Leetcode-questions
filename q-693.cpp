class Solution {
public:
    bool hasAlternatingBits(int n) {
        string s="";
        while(n!=0){
            if(n%2==0){
                if(s.length()>0 && s.back()=='0'){
                    return false;
                }else{
                    s+='0';
                }
            }else{
                if(s.length()>0 && s.back()=='1'){
                    return false;
                }else{
                    s+='1';
                }
            }
            n/=2;
        }
        return true;
    }
};

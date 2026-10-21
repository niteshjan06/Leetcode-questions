class Solution {
public:
    string removeDuplicates(string s) {
        string ans="";

        for(int i=0;i<s.length();i++){
            if(ans.length()==0){
                ans+=s[i];
            }else{
                if(s[i]==ans.back()){
                    ans.pop_back();
                }else{
                    ans+=s[i];
                }
            }
        }
        return ans;
    }
};

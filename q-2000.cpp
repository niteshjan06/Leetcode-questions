class Solution {
public:
    string reversePrefix(string word, char ch) {
        string ans="";
        int flag=0;
        for(int i=0;i<word.length();i++){
            ans+=word[i];
            if(ch==word[i] && flag==0){
                reverse(ans.begin(),ans.end());
                flag=1;
            }
        }
        return ans;
    }
};

class Solution {
public:
    string convertToTitle(int columnNumber) {
        int rem=0;
        int digit;
        string ans="";
        while(columnNumber>0){
            columnNumber--;

            int rem=columnNumber%26;
            ans+=char(rem+'A');

            columnNumber/=26;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

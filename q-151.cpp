class Solution {
public:
    string reverseWords(string s) {
        int i=0;
        int j=0;
        vector<string> temp;
        while(i<s.length() && j<s.length()){
            while(i<s.length() && s[i]==' '){
                i++;
            }
            j=i;
            while(j<s.length() && s[j]!=' '){
                j++;
            }

            if(i<j) temp.push_back(s.substr(i,j-i));
            i=j;
        }

        string ans="";
        for(int i=temp.size()-1;i>=0;i--){
            ans+=temp[i];
            if(i!=0) ans+=" ";
        }

        return ans;
    }
};

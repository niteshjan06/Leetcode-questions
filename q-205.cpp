class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size()){
            return false;
        }

        map<char,char> mp;
        map<char,char> rev;

        for(int i=0;i<s.length();i++){
            if(mp.find(s[i])!=mp.end()){
                if(mp[s[i]]!=t[i]){
                    return false;
                }
            }else{
                if(rev.find(t[i])!=rev.end()){
                    return false;
                }
                mp[s[i]]=t[i];
                rev[t[i]]=s[i];
            }
        }
        return true;
    }
};

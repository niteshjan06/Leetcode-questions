class Solution {
public:
    bool rotateString(string s, string t) {
        if(t.size()!=s.size()){
            return false;
        }

        string temp=s+s;

        return temp.find(t)!=string::npos;
    }
};

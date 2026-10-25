class Solution {
public:
    int countSegments(string s) {
        int countSpaces=0;
        for(int i=0;i<s.length();i++){
            if(s[i]!=' ' && (i==0 || s[i-1] == ' ')){
                countSpaces++;
            }
        }
        return countSpaces;
    }
};

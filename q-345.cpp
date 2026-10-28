class Solution {
public:

    bool isVowel(char ch){
        if(ch=='A' || ch=='a' || ch=='E' || ch=='e' || ch=='I' || ch=='i' || ch=='O' || ch=='o' || ch=='U' || ch=='u'){
            return true;
        }
        return false;
    }

    string reverseVowels(string s) {
        int i=0;
        int j=s.length()-1;
        while(i<j){
            while(i<j && !isVowel(s[i])){
                i++;
            }
            while(i<j && !isVowel(s[j])){
                j--;
            }
            if(i<j){
                swap(s[i],s[j]);
                i++;
                j--;
            }
        }
        return s;
    }
};

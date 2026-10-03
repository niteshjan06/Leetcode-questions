class Solution {
public:
    int maxDistinct(string s) {
        int arr[26]={0};
        for(int i=0;i<s.length();i++){
            arr[s[i]-'a']++;
        }

        int count=0;
        for(int i=0;i<26;i++){
            if(arr[i]!=0){
                count++;
            }
        }
        return count;
    }
};

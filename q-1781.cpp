class Solution {
public:
    int beautySum(string s) {
        int sum=0;
        for(int i=0;i<s.length();i++){
            int arr[26]={0};
            for(int j=i;j<s.length();j++){
                arr[s[j]-'a']++;
                if(i-j==0){
                    continue;
                }

                int mini=INT_MAX;
                int maxi=0;
                for(int i:arr){
                    if(i>0){
                        mini=min(mini,i);
                        maxi=max(maxi,i);
                    }
                }
                sum+=maxi-mini;
            }
        }
        return sum;
    }
};

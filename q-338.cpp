class Solution {
public:

    int countbits(int n){
        int count=0;
        while(n!=0){
            if(n%2){
                count++;
            }
            n/=2;
        }
        return count;
    }

    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        for(int i=0;i<=n;i++){
            ans[i] = countbits(i);
        }
        return ans;
    }
};

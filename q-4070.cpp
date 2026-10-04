class Solution {
public:
    int minRotations(string s) {
        int current=0;
        int ans=0;
        for(char c:s){
            int next=c-'0';
            int diff=abs(current-next);

            ans+=min(diff,10-diff);

            current=next;
        }
        return ans;
    }
};

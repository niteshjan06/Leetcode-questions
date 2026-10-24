class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        stack<int> st;
        int j=0;
        vector<string> ans;
        for(int i=1;i<=n;i++){
            if(j==target.size()){
                break;
            }
            st.push(i);
            ans.push_back("Push");

            if(!st.empty() && target[j]!=i){
                st.pop();
                ans.push_back("Pop");
            }else{
                j++;
            }
        }
        return ans;
    }
};

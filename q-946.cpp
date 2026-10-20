class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if(pushed.size() != popped.size()){
            return false;
        }

        stack<int> st;
        int j=0;
        for(int i=0;i<pushed.size();i++){
            st.push(pushed[i]);

            while(!st.empty() && st.top()==popped[j]){
                j++;
                st.pop();
            }
        }

        while(j<popped.size()){
            if(popped[j]==st.top()){
                st.pop();
                j++;
            }else{
                return false;
            }
        }
        return st.empty();
    }
};

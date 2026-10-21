class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;

        for(int i=0;i<s.length();i++){
            if(!st.empty() && (s[st.top()]=='(' && s[i]==')')){
                st.pop();
            }else{
                if(s[i]=='(' || s[i]==')'){
                    st.push(i);
                }
            }
        }
        while(!st.empty()){
            s.erase(st.top(),1);
            st.pop();
        }
        return s;
    }
};

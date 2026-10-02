class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(int i=0;i<s.length();i++){
            if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
                st.push(s[i]);
                continue;
            }
            if(!st.empty()){
                char ch=st.top();
                if(ch=='(' && s[i]==')' || ch=='[' && s[i]==']' || ch=='{' && s[i]=='}'){
                    st.pop();
                }else{
                    st.push(s[i]);
                }
            }else{
                st.push(s[i]);
            }
       } 
       return st.empty();
    }
};

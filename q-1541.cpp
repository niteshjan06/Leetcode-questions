class Solution {
public:
    int minInsertions(string s) {
        stack<int> st;
        int count=0;

        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                st.push(s[i]);
            }else{
                if(i+1 < s.length() && s[i+1]==')'){
                    i++;
                }else{
                    count++;
                }

                if(!st.empty()){
                    st.pop();
                }else{
                    count++;
                }
            }
        }

        count+=2*st.size();
        return count;
    }
};

class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        string str="";

        for(int i=0;i<num.length();i++){
            if(st.empty()){
                st.push(num[i]);
            }else{
                if(st.top()>num[i] && k!=0){
                    while(!st.empty() && st.top()>num[i] && k!=0){
                        st.pop();
                        k-=1;
                    }
                    st.push(num[i]);
                }else{
                    st.push(num[i]);
                }
            }
        }

        while(!st.empty() && k--){
            st.pop();
        }

        if(st.empty()){
            return "0";
        }

        while(!st.empty()){
            str+=st.top();
            st.pop();
        }

        reverse(str.begin(),str.end());

        int i=0;
        while(str[i]=='0'){
            i++;
        }

        if(i==str.length()){
            return ("0");
        }

        return str.substr(i,str.length());
    }
};

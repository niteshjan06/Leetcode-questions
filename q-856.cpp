class Solution {
public:
    int scoreOfParentheses(string s) {
        int score=0;
        int tracker=0;

        stack<int> st;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                st.push(tracker);
                tracker=0;
            }
            else{
                int inner=tracker;
                tracker=st.top();
                st.pop();
                if(inner==0){
                    tracker+=1;
                }else{
                    tracker+=2*inner;
                }

                if(st.empty()){
                    score+=tracker;
                    tracker=0;
                }
            }
        }
        return score;
    }
};

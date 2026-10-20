class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> st;

        for(int i=0;i<operations.size();i++){
            if(operations[i]!="C" && operations[i]!="D" && operations[i]!="+"){
                st.push_back(stoi(operations[i]));
            }else{
                if(operations[i]=="C"){
                    if(!st.empty()) st.pop_back();
                }else if(operations[i]=="D"){
                    st.push_back(st.back()*2);
                }else{
                    st.push_back(st[st.size()-1]+st[st.size()-2]);
                }
            }
        }

        int sum=0;
        for(int i=0;i<st.size();i++){
            sum+=st[i];
        }
        return sum;
    }
};

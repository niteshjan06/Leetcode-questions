class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;

        for(int i=0;i<asteroids.size();i++){
            if(st.size()==0){
                st.push_back(asteroids[i]);
            }else if(asteroids[i]>=0){
                st.push_back(asteroids[i]);
            }else{
                int destroy=0;
                while(st.size()!=0 &&st.back()>0){
                    if(st.back()>=abs(asteroids[i])){
                        destroy=1;
                    }
                    if(st.back()<=abs(asteroids[i])) st.pop_back();
                    if(destroy){
                        break;
                    }
                }
                if(!destroy){
                    st.push_back(asteroids[i]);
                }
            }
        }
        return st;
    }
};

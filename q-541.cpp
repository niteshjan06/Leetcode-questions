class Solution {
public:
    string reverseStr(string s, int k) {
        int size=0;
        while(size<s.length()){
            if(size+k > s.length()){
                reverse(s.begin()+size,s.end());
                break;
            }
            reverse(s.begin()+size,s.begin()+size+k);
            size+=2*k;
        }
        return s;
    }
};

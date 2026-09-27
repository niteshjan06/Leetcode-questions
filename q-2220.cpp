class Solution {
public:

    int countBits(int n){
        int count=0;
        while(n>0){
            count+=n&1;
            n/=2;
        }
        return count;
    }

    int minBitFlips(int start, int goal) {
        int num=start^goal;
        return countBits(num);
    }
};

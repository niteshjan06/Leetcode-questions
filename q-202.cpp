class Solution {
public:

    int DigitSquareSum(int n){
        int sum=0;
        while(n!=0){
            sum+=(pow(n%10,2));
            n/=10;
        }
        return sum;
    }

    bool isHappy(int n) {
        map<int,int> hash;
        while(n!=1 && hash.find(n) == hash.end()){
            hash[n]=n;
            n=DigitSquareSum(n);
        }
        if(n!=1){
            return false;
        }
        return true;
    }
};

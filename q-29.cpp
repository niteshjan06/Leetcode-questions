class Solution {
public:
    int divide(int dividend, int divisor) {
        bool sign=true;
       if((dividend<0 && divisor>0) || (dividend>0 && divisor<0)){
            sign=false;
       }

        long ans=0;
        long n=labs((long)dividend);
        long d=labs((long)divisor);
        while(n>=d){
            int count=0;

            while(n>=(d<<(count+1))){
                count++;
            }

            ans+=(1LL<<count);
            n-=(d<<count);
        }

        if(!sign){
            ans=-ans;
        }
        if(ans>INT_MAX){
            return INT_MAX;
        }
        if(ans<INT_MIN){
            return INT_MIN;
        }
        return (int)ans;
    }
};

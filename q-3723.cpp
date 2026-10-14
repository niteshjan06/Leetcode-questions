class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum>num*9){
            return "";
        }

        string str="";
        while(num){
            if(sum>=9){
                str+='9';
                sum-=9;
            }else{
                str+=char(sum+'0');
                sum=0;
            }
            num--;
        }
        return str;
    }
};

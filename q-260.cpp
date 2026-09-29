class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long x=0;
        for(int i=0;i<nums.size();i++){
            x^=nums[i];
        }

        int rightmost=(x&x-1)^x;
        int b1=0,b2=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]&rightmost){
                b1^=nums[i];
            }else{
                b2^=nums[i];
            }
        }
        return {b1,b2};
    }
};

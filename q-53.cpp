class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0;
        int highest=nums[0];

        for(int i=0;i<nums.size();i++){
            sum += nums[i];

            highest = max(highest, sum);
            
            if(sum < 0){
                sum = 0;
            }
        }
        return highest;
    }
};

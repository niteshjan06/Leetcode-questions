class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> result(nums.size());

        int i=0;
        int j=1;
        for(int k=0;k<nums.size();k++){
            if(nums[k] < 0){
                result[j] = nums[k];
                j+=2;
            }else if(nums[k] > 0){
                result[i] = nums[k];
                i+=2;
            }
        }
        return result;
    }
};

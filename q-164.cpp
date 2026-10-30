 class Solution {
public:
    int maximumGap(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int largestDifferernce=0;

        for(int i=0;i<nums.size()-1;i++){
            largestDifferernce=max(largestDifferernce,abs(nums[i]-nums[i+1]));
        }
        return largestDifferernce;
    }
};

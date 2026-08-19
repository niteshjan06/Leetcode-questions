class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int> hash;
        hash[0]=1;
        int count=0;
        int prefix_sum=0;
        for(int i=0;i<nums.size();i++){
            prefix_sum+=nums[i];
            count+=hash[prefix_sum-k];
            hash[prefix_sum]++;
        }
        return count;
    } 
};

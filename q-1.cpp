class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hash;
        int more;

        for(int i=0;i<nums.size();i++){
            more = target - nums[i];

            if(hash.find(more) != hash.end()){
                return {hash[more],i};
            }
            hash[nums[i]] = i;
        }

        return {};
    }
};

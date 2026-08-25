class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prefix=1;
        int suffix=1;
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            prefix*=nums[i];
            suffix*=nums[nums.size()-i-1];
            maxi=max(suffix,max(maxi,prefix));
            if(suffix==0){
                suffix=1;
            }
            if(prefix==0){
                prefix=1;
            }
        }
        return maxi;
    }
};

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {

        for(int i=0;i<nums.size();i++){
            if(nums[i]<0){
                nums[i]=abs(nums[i]);
            }
        }

        sort(nums.begin(),nums.end());

        int i=0;
        int j=nums.size()-1;

        long long sum=0;
        while(i<=j){
            if(i==j){
                sum+=(nums[i]*1LL*nums[i]);
                break;
            }

            sum+=((nums[j]*1LL*nums[j])-(nums[i]*1LL*nums[i]));
            i++;
            j--;
        }
        return sum;
    }
};

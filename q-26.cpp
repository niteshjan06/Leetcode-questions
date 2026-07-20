class Solution {
public:
    int removeDuplicates(vector<int>& nums) { // function to remove duplicate elements from an array.
        int i=0; 
        int j=1;
        while(j < nums.size()){  // using two-pointer approach to solve this.
            if(nums[i] != nums[j]){
                nums[++i] = nums[j];
                j++;
            }else if(nums[i] == nums[j]){
                j++;
            }
        }
        return i+1; // returns the size of the modified array.
    }
};

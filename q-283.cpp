class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=0; // one pointer i.
        int j=1; // second pointer j.
        int temp;
        if(nums.size() <= 1){ // return if array size is 1 or less.
            return ;
        }
        while(i != nums.size()-1 && j < nums.size()){ // condition for iteration
            if(nums[i] == 0){ // checks if i is zero or not.
                if(nums[j] != 0){ // if j is not zero if will swap.
                    temp = nums[i];
                    nums[i] = nums[j];
                    nums[j] = temp;
                    i++;
                    j++;
                }else{
                    j++;
                }
            }else{
                i++;
                j++;
            }
        }
    }
};

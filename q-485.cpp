class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max = 0;
        int count = 0;
        for(int i : nums){ //for each loop for iterating each element in the array.
            if(i == 0){ // if i is 0 reset the counter.
                if(count > max){ // if counter is greater than max.
                    max = count;
                }
                count = 0;
            }else{
                count++; //increamenting counter.
            }
        }
        if(count > max){
            max = count;
        }
        return max;
    }
};

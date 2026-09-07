class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        if(numbers.size() == 2){
            return {1,2};
        }
        int i=0;
        int j=numbers.size()-1;
        for(int i=0;i<numbers.size();){
            if(numbers[i]+numbers[j] == target){
                return {i+1,j+1};
            }

            if(i >= j){
                break;
            }

            if(numbers[i]+numbers[j] > target){
                j--;
            }else{
                i++;
            }
        }
        return {j,i};
    }
};

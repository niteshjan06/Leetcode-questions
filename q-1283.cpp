class Solution {
public:

    int max_el(vector<int> &arr){
        int largest=INT_MIN;

        for(int i=0;i<arr.size();i++){
            if(largest < arr[i]){
                largest = arr[i];
            }
        }
        return largest;
    }

    long long findResult(vector<int> &arr, int divisor){
        long long sum=0;
        for(int i=0;i<arr.size();i++){
            sum+=ceil((double)arr[i]/(double)divisor);
        }
        return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1;
        int high=max_el(nums);

        while(low<=high){
            int mid=low+(high-low)/2;

            long long result = findResult(nums,mid);
            if(result <= threshold){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
};

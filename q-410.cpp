class Solution {
public:
    
    int placedArrays(vector<int> &arr, long long mid){
        int count=1;
        long long sum=0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            if(sum>mid){
                count++;
                sum=arr[i];
            }
        }
        return count;
    }

    long long sumOf(vector<int> &arr){
        long long sum=0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
        }
        return sum;
    }

    int max_el(vector<int> &arr){
        int largest=INT_MIN;

        for(int i=0;i<arr.size();i++){
            if(largest < arr[i]){
                largest=arr[i];
            }
        }
        return largest;
    }

    int splitArray(vector<int>& nums, int k) {
        int low=max_el(nums);
        long long high=sumOf(nums);

        while(low<=high){
            long long mid=low+(high-low)/2;

            if(placedArrays(nums,mid) > k){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return low;
    }
};

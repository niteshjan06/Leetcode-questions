class Solution {
public:
    int search(vector<int>& arr, int target) {
        int ans=-1;

        int low=0;
        int high=arr.size()-1;

        while(low<=high){
            int mid=low+(high-low)/2;

            if(arr[mid]==target){
                ans=mid;
                high=mid-1;
            }else if(arr[mid]>target){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};

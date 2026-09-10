class Solution {
public:

    int max_el(vector<int> &arr){
        int largest=INT_MIN;
        for(int i=0;i<arr.size();i++){
            if(largest < arr[i]){
                largest=arr[i];
            }
        }
        return largest;
    }

    int sumOf(vector<int> &arr){
        int sum=0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
        }
        return sum;
    }

    int dayRequired(vector<int> &arr, int mid){
        int day=0;
        int sum=0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            if(sum>mid){
                day++;
                i--;
                sum=0;
            }
        }
        return day+1;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low=max_el(weights);
        int high=sumOf(weights);
        int ans=0;
        while(low<=high){
            int mid=(low+high)/2;
            int mid_day = dayRequired(weights,mid);

            if(mid_day <= days){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};

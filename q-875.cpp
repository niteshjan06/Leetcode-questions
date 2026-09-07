class Solution {
public:

    long long findHours(vector<int> arr,int mid){
        long long hours=0;

        for(int i=0;i<arr.size();i++){
            hours += long(ceil((double)arr[i]/(double)mid));
        }
        return hours;
    }

    int max_el(vector<int> &arr){
        int largest=INT_MIN;

        for(int i=0;i<arr.size();i++){
            if(largest < arr[i]){
                largest = arr[i];
            }
        }
        return largest;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=max_el(piles);
        int ans=piles.size();
        while(low<=high){
            int mid=low+(high-low)/2;

            long long hours = findHours(piles,mid);

            if(hours <= h){
                high=mid-1;
                ans=mid;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};

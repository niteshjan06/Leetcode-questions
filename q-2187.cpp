class Solution {
public:

    long long Trips(vector<int> &time, long long x){
        long long count=0;
        for(int i=0;i<time.size();i++){
            count+=(x/time[i]);
        }
        return count;
    }

    long long min_el(vector<int> &arr){
        long long mini=arr[0];
        for(int i=0;i<arr.size();i++){
            if(mini>arr[i]){
                mini=arr[i];
            }
        }
        return mini;
    }

    long long minimumTime(vector<int>& time, int totalTrips) {
        long long low=1;
        long long high=min_el(time)*1LL*totalTrips;

        while(low<=high){
            long long mid=low+(high-low)/2;

            if(Trips(time,mid) >= totalTrips){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
};

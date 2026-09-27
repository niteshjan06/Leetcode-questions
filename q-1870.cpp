class Solution {
public:

    double timeTaken(vector<int> &arr, int n){
        double time=0;
        for(int i=0;i<arr.size()-1;i++){
            time+=ceil(double(arr[i])/double(n));
        }
        time+=double(arr[arr.size()-1])/double(n);
        return time;
    }

    int min_el(vector<int> &arr){
        int smallest=INT_MIN;
        for(int i=0;i<arr.size();i++){
            smallest=min(smallest,arr[i]);
        }
        return smallest;
    }

    int minSpeedOnTime(vector<int>& dist, double hour) {
        if(hour <= dist.size()-1){
            return -1;
        }

        int low=1;
        long long high=10000000;
        while(low<=high){
            int mid=low+(high-low)/2;

            if(timeTaken(dist,mid) <= hour){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
};

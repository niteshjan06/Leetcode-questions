class Solution {
public:

    int findBouquets(vector<int> &arr,int day,int k){
        int bouquets=0;
        int count=0;
        for(int i=0;i<arr.size();i++){
            if(day>=arr[i]){
                count++;
            }else{
                bouquets+=(count/k);
                count=0;
            }
        }
        bouquets+=(count/k);
        return bouquets;
    }

    long max_el(vector<int> &arr){
        long largest=INT_MIN;

        for(int i=0;i<arr.size();i++){
            if(largest < arr[i]){
                largest = arr[i];
            }
        }
        return largest;
    }

    long min_el(vector<int> &arr){
        long smallest=INT_MAX;

        for(int i=0;i<arr.size();i++){
            if(smallest > arr[i]){
                smallest = arr[i];
            }
        }
        return smallest;
    }
    int bouquets;
    int minDays(vector<int>& bloomDay, int m, int k) {
        long low=min_el(bloomDay);
        long high=max_el(bloomDay);

        while(low<=high){
            long mid=low+(high-low)/2;

            bouquets = findBouquets(bloomDay,mid,k);

            if(bouquets >= m){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        if((long long)m*k > bloomDay.size()){
            return -1;
        }
        return low;
    }
};

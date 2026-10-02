class Solution {
public:
    bool weCanPlace(int m,int mid,vector<int>& arr){
        int last_ball=arr[0];
        int sum=0;
        int count=1;
        for(int i=1;i<arr.size();i++){
            if(arr[i]-last_ball>=mid){
                last_ball=arr[i];
                count++;
            }
        }
        return count>=m;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());

        int low=1;
        int high=position[position.size()-1]-position[0];

        while(low<=high){
            int mid=low+(high-low)/2;

            if(weCanPlace(m,mid,position)){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return high;
    }
};

class Solution {
public:

    int findLargest(vector<int> &arr){
        int largest=INT_MIN;
        for(int i=0;i<arr.size();i++){
            if(largest<arr[i]){
                largest=arr[i];
            }
        }
        return largest;
    }

    int findSlargest(vector<int> &arr){
        int largest=INT_MIN;
        int slargest=INT_MIN;
        for(int i=0;i<arr.size();i++){
            if(largest<arr[i]){
                slargest=largest;
                largest=arr[i];
            }else if(slargest<arr[i]){
                slargest=arr[i];
            }
        }
        return slargest;
    }

    int findIndex(vector<int> &arr,int l){
        int index=-1;
        for(int i=0;i<arr.size();i++){
            if(l==arr[i]){
                index=i;
                break;
            }
        }
        return index;
    }

    int dominantIndex(vector<int>& nums) {
        int largest=findLargest(nums);
        int largestIndex=findIndex(nums,largest);
        int slargest=findSlargest(nums);

        if(largest >= slargest*2){
            return largestIndex;
        }
        return -1;
    }
};

class Solution {
public:

    int maxElement(vector<vector<int>> &arr,int n,int col){
        int largest=INT_MIN;
        int index=-1;
        
        for(int i=0;i<n;i++){
            if(arr[i][col] > largest){
                largest=arr[i][col];
                index=i;
            }
        }
        return index;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int low=0;
        int high=mat[0].size()-1;
        
        while(low<=high){
            int mid=low+(high-low)/2;
            
            int row=maxElement(mat,mat.size(),mid);
            
            int left=mid-1>=0?mat[row][mid-1]:INT_MIN;
            int right=mid+1<mat[0].size()?mat[row][mid+1]:INT_MIN;
            
            if(mat[row][mid] >= left && mat[row][mid] >= right){
                return {row,mid};
            }else if(mat[row][mid] < left){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return {-1,-1};
    }
};

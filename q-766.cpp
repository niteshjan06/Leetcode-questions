class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& mat) {
        for(int i=0;i<mat.size();i++){
            int j=0,k=i;
            while(k<mat.size()-1 && j<mat[0].size()-1){
                if(mat[k][j] != mat[k+1][j+1]){
                    return false;
                }
                j++,k++;
            }
        }

        for(int i=1;i<mat[0].size();i++){
            int j=0,k=i;
            while(k<mat[0].size()-1 && j<mat.size()-1){
                if(mat[j][k] != mat[j+1][k+1]){
                    return false;
                }
                j++,k++;
            }
        }
        return true;
    }
};

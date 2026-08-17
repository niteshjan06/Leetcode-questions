class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int count = 1;   // first column
        int row = 1;     // first row

        // Check first column
        for(int i = 0; i < matrix.size(); i++){
            if(matrix[i][0] == 0){
                count = 0;
            }
        }

        // Check first row
        for(int j = 0; j < matrix[0].size(); j++){
            if(matrix[0][j] == 0){
                row = 0;
            }
        }

        // Mark rows and columns
        for(int i = 1; i < matrix.size(); i++){
            for(int j = 1; j < matrix[0].size(); j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // Set inner matrix
        for(int i = 1; i < matrix.size(); i++){
            for(int j = 1; j < matrix[0].size(); j++){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }

        // First column
        if(count == 0){
            for(int i = 0; i < matrix.size(); i++){
                matrix[i][0] = 0;
            }
        }

        // First row
        if(row == 0){
            for(int j = 0; j < matrix[0].size(); j++){
                matrix[0][j] = 0;
            }
        }
    }
};

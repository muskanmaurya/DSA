class Solution {
public:

    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(); //number of rows
        int n = matrix[0].size(); //number of columns
        int col0=1; // Special tracking variable strictly for the 0th column
        // Traverse the matrix to flag rows and columns that need to be zeroed
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    // Mark the prefix indicator for the i-th row
                    matrix[i][0]=0;
                    // Mark the prefix indicator for the j-th column
                    if(j!=0){
                        matrix[0][j]=0;
                    }
                    // If the cell belongs to column 0, update our independent tracker
                    else col0=0;
                }
            }
        }
        // Update the inner elements (from index 1,1) based on the boundary flags
        // We traverse backwards or from (1,1) onwards so we do not overwrite the tracking flags prematurely
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i][0]==0 || matrix[0][j]==0){
                    matrix[i][j]=0;
                }
            }
        }
        // Explicitly handle the tracking indicators for the first row and column
        // If the absolute corner element matrix[0][0] is flagged, zero out the entire first row
        if(matrix[0][0]==0){
            for(int j=0;j<n;j++){
                matrix[0][j]=0;
            }
        }
        // If our independent tracker col0 is flagged, zero out the entire first column
        if(col0==0){
            for(int i=0;i<m;i++){
                matrix[i][0]=0;
            }
        }
    }
};
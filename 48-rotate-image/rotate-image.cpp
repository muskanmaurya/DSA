class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //Bruteforce Method
        int m=matrix.size(); //number of rows
        int n=matrix[0].size(); //number of columns
        vector<vector<int>> ans; // Temporary 2D vector to store the rotated matrix
        // Loop through each column of the original matrix from left to right
        for(int i=0;i<m;i++){
        vector<int> row; // Temporary 1D vector to construct the new rotated row
        // Traverse the current column 'i' from bottom to top (backwards)
            for(int j=n-1;j>=0;j--){
                // Collect elements to form the new row configuration
                row.push_back(matrix[j][i]);
            }
            // Push the fully constructed row into our temporary 2D matrix
            ans.push_back(row);
        }
        // Copy the rotated state from 'ans' back into the original 'matrix' (In-place reference update)
        matrix=ans;
    }
};
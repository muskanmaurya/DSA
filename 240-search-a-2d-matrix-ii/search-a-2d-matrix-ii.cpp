class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(); // Number of rows
        int n = matrix[0].size(); // Number of columns
        // Start from the top-right corner of the matrix
        int row = 0; 
        int col = n-1;

        // Loop runs until we cross the matrix boundaries
        while(row < m && col >= 0 ){
            // Found the target!
            if(target == matrix[row][col]) return true;
            // Current element is greater than target. 
            // Since columns are sorted top-to-bottom, all elements below this are also strictly greater than target. Eliminate the whole column!
            else if(target < matrix[row][col]) col--;
            // Current element is smaller than target.
            // Since rows are sorted left-to-right, all elements to the left are also strictly smaller. Eliminate the whole row!
            else row++;
        }
        // Target not found after exhausting search space
        return false;
    }
};
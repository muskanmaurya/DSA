class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // Optimal Method: Achieves 90-degree clockwise rotation in-place
        int m=matrix.size(); //number of rows
        int n=matrix[0].size(); //number of columns
        //In-place Transpose (Reflecting elements across the main diagonal)
        for(int i=0;i<m;i++){
        // CRITICAL OPTIMIZATION: Start 'j' from 'i' to traverse only the Upper Triangle.
            // This prevents double-swapping elements back to their original positions.
            for(int j=i;j<n;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        // Horizontal Reflection (Reversing each row independently)
        for(int i=0;i<n;i++){
            // Using C++ STL iterators to reverse row elements in-place.
            // This flips the transposed columns into their correct rotated order.
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};
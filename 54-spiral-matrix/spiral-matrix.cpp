class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int> ans;
        int srow=0, scol=0, erow=m-1, ecol=n-1;
        while(srow<=erow && scol<=ecol){
            //top: Move left to right on the 'srow' boundary
            for (int j = scol; j <= ecol; j++) { 
                ans.push_back(matrix[srow][j]);
            }
            srow++; // Row top boundary push down
            
            //right: Move top to bottom on the 'ecol' boundary
            for (int i = srow; i <= erow; i++) {
                ans.push_back(matrix[i][ecol]);
            }
            ecol--; // Column right boundary push left
            
            //bottom: Move right to left on the 'erow' boundary (if rows remain)
            if (srow <= erow) { //Safe check for remaining rows
                for (int j = ecol; j >= scol; j--) {
                    ans.push_back(matrix[erow][j]); 
                }
                erow--; // Row bottom boundary push up
            }
            
            //left: Move bottom to top on the 'scol' boundary (if cols remain)
            if (scol <= ecol) { //Safe check for remaining columns
                for (int i = erow; i >= srow; i--) {
                    ans.push_back(matrix[i][scol]);
                }
                scol++; // Column left boundary push right
            }
        }
    return ans;
    }
};
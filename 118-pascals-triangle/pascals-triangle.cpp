class Solution {
public:
    // helper function to generate a single 1-based row of Pascal's Triangle
    vector<int> generateRow(int row){
        long long ans = 1;
        vector<int> ansRow;
        ansRow.push_back(1); //The first element of any row is always 1
        for(int col = 1; col < row; col++){
            //using the combination formula transformation: ans = ans * (n - r) / r
            ans = ans * (row - col);
            ans = ans / col;
            // Push the calculated element into the row vector
            ansRow.push_back(ans);
        }

        return ansRow;
    }

    // Main function to return the first numRows of Pascal's triangle
    vector<vector<int>> generate(int numRows) {   
        vector<vector<int>> ans;
        //Generate each row sequentially using 1-based indexing
        for(int i = 1; i <= numRows; i++){
            ans.push_back(generateRow(i));
        } 
        return ans;
    }
};
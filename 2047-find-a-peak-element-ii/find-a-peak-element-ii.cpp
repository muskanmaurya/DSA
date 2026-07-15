class Solution {
public:
    //helper function to find max elem in that col
    int findMaxIdx(vector<vector<int>>& mat, int col, int m, int n){
        int maxVal = -1;
        int maxIdx = -1;
        for(int i = 0; i < m; i++){
            if(mat[i][col] > maxVal){
                maxVal = mat[i][col];
                maxIdx = i;
            }
        }
        return maxIdx;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        //Optimal binary search
        int st = 0, end = n - 1;
        while(st <= end){
            int mid = st + (end - st) / 2;
            int maxRowIdx = findMaxIdx(mat, mid, m, n);
            int left = mid - 1 >= 0 ? mat[maxRowIdx][mid - 1] : -1;
            int right = mid + 1 < n ? mat[maxRowIdx][mid + 1] : -1;
            if(mat[maxRowIdx][mid] > left && mat[maxRowIdx][mid] > right) return {maxRowIdx, mid};
            else if(mat[maxRowIdx][mid] < left) end = mid - 1;
            else st = mid + 1;
        }
        return {-1, -1};
    }
};
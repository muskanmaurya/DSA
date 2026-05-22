class Solution {
public:

    bool searchRow(vector<vector<int>>& matrix,int row, int target){
        //binary search on taregt element row
        int n = matrix[0].size(); //Column size of the target row
        int st = 0, end = n-1; //startRowElement, endRowElement
        while(st <= end){
            int mid = st + (end - st) / 2; //midElement of the row
            if (target == matrix[row][mid]) return true;
            else if (target >= matrix[row][mid]) st = mid + 1;
            else end = mid - 1;
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //binary search on all rows 
        int m = matrix.size(); //row size
        int n = matrix[0].size();  //column size
        int st = 0, end = m - 1; //startRow, endRow
        while(st <= end){
            int mid = st + (end - st) / 2;  //midRow
            if(target >= matrix[mid][0] && target <= matrix[mid][n-1]){
                //function for searching the target in the target row
                return searchRow(matrix, mid, target); 
            }else if(target >= matrix[mid][n-1]){
                st = mid + 1;
            }else {
                end = mid - 1;
            }
        }  
        return false;
    }
};
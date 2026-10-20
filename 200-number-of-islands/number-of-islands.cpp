class Solution {
public:
    void search(int i, int j, vector<vector<char>>& grid, int n, int m){
        if(i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == '0'){
            return;
        }
        grid[i][j] = '0';

        search(i - 1, j, grid, n, m);
        search(i + 1, j, grid, n, m);
        search(i, j - 1, grid, n, m);
        search(i, j + 1, grid, n, m);
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '1'){
                    cnt++;
                    search(i, j, grid, n, m);
                }
            }
        }
        return cnt;
    }
};
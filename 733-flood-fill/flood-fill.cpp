class Solution {
public:
    void fill(int i, int j, vector<vector<int>>& image, int ogcolor, int color, int n, int m){
        if(i < 0 || i >= n || j < 0 || j >= m || image[i][j] != ogcolor){
            return;
        }

        image[i][j] = color;

        fill(i - 1, j, image, ogcolor, color, n, m);
        fill(i + 1, j, image, ogcolor, color, n, m);
        fill(i, j - 1, image, ogcolor, color, n, m);
        fill(i, j + 1, image, ogcolor, color, n, m);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int ogcolor = image[sr][sc];

        if(ogcolor == color) return image;

        fill(sr, sc, image, ogcolor, color, n, m);
        return image;
    }
};
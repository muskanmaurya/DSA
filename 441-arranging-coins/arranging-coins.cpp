class Solution {
public:
    int arrangeCoins(int n) {
        int cnt = n;
        int row = 1;
        while(cnt >= row){
            cnt -= row;
            row++;
        }
        return row - 1;
    }
};
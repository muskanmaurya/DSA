class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num == 0 || num == 1) return num;
        int st = 2, end = num - 1;
        while(st <= end){
            long long mid = st + (end - st) / 2;
            long long root = mid * mid;
            if(root == num) return true;
            else if(root < num) st = mid + 1;
            else end = mid - 1;
        }
        return false;
    }
};
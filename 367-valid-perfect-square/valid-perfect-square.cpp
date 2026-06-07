class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num == 0 || num == 1) return num;
        // FIXED: Using 'long long' for 'i' to prevent integer overflow when calculating i*i.
        // Also, we change the loop condition to stop the moment i*i crosses 'num'.
        for(long long i = 0;i < num; i++){
            // If the square perfectly matches our target, it's a valid perfect square!
            if(i * i == num)return true;
        }
        // If the loop finishes without finding a perfect match, num is not a perfect square
        return false;
    }
};
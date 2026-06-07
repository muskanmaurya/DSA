class Solution {
public:
    int mySqrt(int x) {
        // Edge Case: If x is 0 or 1, its square root is the number itself.
        // Handling this early prevents loop boundary bugs.
        if(x == 0 || x == 1) return x;
        // FIXED: Using 'long long' for the loop tracker 'i' to completely 
        // prevent integer overflow when calculating 'i * i' for large inputs.
        for(long long i = 0; i < x; i++){
            // Case 1: Perfect square found!
            if(i * i == x){
                return i;
            }
            // Case 2: The exact moment the square crosses 'x', the previous
            // integer (i - 1) is our perfect rounded-down floor value.
            else if(i * i > x){
                return i - 1;
            }
        }
        return 1;
    }
};
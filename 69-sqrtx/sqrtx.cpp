class Solution {
public:
    int mySqrt(int x) {
        // Safe Edge Cases: The square root of 0 or 1 is the number itself
        if(x == 0 || x == 1) return x;
        // Since we handled 0 and 1, our active search space is securely [2 to x-1]
        int st = 2, end = x - 1;
        int ans = 1; // Default floor placeholder
        while(st <= end){
            int mid = st + (end - st) / 2;
            // Using long long prevents overflow when mid * mid crosses 2^31 - 1
            long long root = (long long)mid * mid;
            // Case 1: Perfect square match found!
            if(root == x) return mid;
            // Case 2: Too big! Eliminate this mid and everything to its right
            else if(root > x) {
                end = mid - 1;
            }
            // Case 3: Too small! This is a valid floor candidate. Save it and push right.
            else{
                ans = mid;
                st = mid + 1;
            }
        }
    return ans;
    }
};
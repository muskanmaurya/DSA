class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        // Initialize global maximum with the lowest possible integer value
        int ans=INT_MIN;
        // Running products from the start (prefix) and from the end (suffix)
        int prefix=1, suffix=1;
        for(int i=0;i<n;i++){
            // If the previous element was 0, it wiped out our product.
            // We reset the running product back to 1 to start a new subarray window.
            if(prefix==0)prefix=1;
            if(suffix==0)suffix=1;
            // Calculate prefix product from left to right
            prefix=prefix*nums[i];
            // Calculate suffix product from right to left
            // When i = 0, n-1-i is the last element. When i = n-1, it's the first element.
            suffix=suffix*nums[n-i-1];
            // The maximum product seen so far from either direction is our current best
            ans=max(ans, max(prefix,suffix));
        }
        return ans;
    }
};
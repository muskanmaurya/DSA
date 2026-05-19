class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        // According to the DNF algorithm init three pointers: 
        // 'low' tracks the boundary for 0s (Red)
        // 'mid' is the iterator scanning the array from left to right
        // 'high' tracks the boundary for 2s (Blue)
        int low = 0, mid = 0, high = n-1;
        while (mid <= high) {  // Loop runs until the scanning pointer 'mid' crosses 'high'
           
            if (nums[mid] == 0) {  // Case 1: If the current element is 0
                swap(nums[mid], nums[low]); // Swap it with the element at the 'low' pointer to send it to the left side
                mid++, low++; // Move the scanning and 0-boundary pointer forward
            } 
            else if (nums[mid] == 1) {  // Case 2: If the current element is 1
                mid++; // 1 is already in its correct middle zone, so just move 'mid' forward
            } 
            else { // Case 3: If the current element is 2
                swap(nums[mid], nums[high]); // Swap it with the element at the 'high' pointer to send it to the right side
                high--; // Move the 2-boundary pointer inward
                // Note: We do NOT increment 'mid' here because the swapped element from the 'high' index is unexplored and needs to be evaluated in the next iteration.
            }
        }
    }
};
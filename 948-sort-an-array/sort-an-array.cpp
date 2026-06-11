class Solution {
public:
    // Helper function to merge two sorted sections of the array back together
    void merge(vector<int>& nums, int st, int mid, int end){
        vector<int> temp;
        int i = st;
        int j = mid + 1;
        // Step 1: Compare elements from both halves and pick the smaller one sequentially
        while(i <= mid && j <= end){
            if(nums[i] < nums[j]) {temp.push_back(nums[i]); i++;}
            else {temp.push_back(nums[j]); j++;}
        }
        // Step 2: If elements remain in the left half, copy them to temp
        while(i <= mid) {temp.push_back(nums[i]); i++;}
        // Step 3: If elements remain in the right half, copy them to temp
        while(j <= end) {temp.push_back(nums[j]); j++;}
        // Step 4: Overwrite the original array segment with the sorted elements from temp
        for(int i = 0; i < temp.size(); i++){
            nums[st + i] = temp[i];
        }
    }
    // Recursive function that divides the array into individual elements
    void mergeSort(vector<int>& nums, int st, int end){
        if(st >= end)return;
        // Calculate the center point to split the array securely without integer overflow
        int mid = st + (end - st) / 2;
        // Recursively break down the left half and the right half
        mergeSort(nums, st, mid);
        mergeSort(nums, mid+1, end);
        // Stitch the two sorted halves back together in perfect order
        merge(nums, st, mid, end);
    }
    // Main function called by LeetCode
    vector<int> sortArray(vector<int>& nums) {
        int st = 0;
        int end = nums.size() - 1;
        // Kick off the merge sort process on the entire array space
        mergeSort(nums, st, end);
        return nums;
    }
};
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //tracking from backward
        int i = m-1; 
        int j = n-1;
        int p = m+n-1;
        while(i >= 0 && j >= 0){
            // This handles when nums1[i] > nums2[j]
            if(nums1[i] > nums2[j]){
                nums1[p] = nums1[i];
                i--;
            }
            else {
                // This handles both nums2[j] > nums1[i] AND when they are equal!
                nums1[p] = nums2[j];
                j--;
            }
            p--; // Decrement the placement pointer in every iteration out here
        }
        // If nums2 still has leftover elements, copy them over
        while (j >= 0) {
            nums1[p] = nums2[j];
            j--;
            p--;
        }
    }
};
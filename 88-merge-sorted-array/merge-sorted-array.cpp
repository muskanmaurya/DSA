class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //Fill the dummy slots at the back of nums1 with nums2 elements.
        // We start our index loop from 'm' (where the real data of nums1 ends).
        for(int i = m; i < nums1.size(); i++){
            // 'i - m' correctly maps indices 0, 1, 2... of nums2 
            // into indices m, m+1, m+2... of nums1
            nums1[i] = nums2[i - m];
        }
        // Now that nums1 contains all elements from both arrays,
        // it is completely unsorted. We use the built-in sort method to sort the array
        sort(nums1.begin(), nums1.end());
    }
};
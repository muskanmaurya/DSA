class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merged;
        int i = 0, n1 = nums1.size();
        int j = 0, n2 = nums2.size();
        while(i < n1 && j < n2){
            if(nums1[i] < nums2[j]) merged.push_back(nums1[i++]);
            else merged.push_back(nums2[j++]);
        }

        while (i < nums1.size()) merged.push_back(nums1[i++]);
        while (j < nums2.size()) merged.push_back(nums2[j++]);

        int n = n1 + n2;
        if (n % 2 != 0) return merged[n / 2];
        else return (merged[(n / 2) - 1] + merged[n / 2]) / 2.0; 
    }
};
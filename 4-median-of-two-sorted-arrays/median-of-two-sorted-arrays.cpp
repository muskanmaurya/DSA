class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, n1 = nums1.size();
        int j = 0, n2 = nums2.size();
        int n = n1 + n2;
        int idx2 = n / 2;
        int idx1 = idx2 - 1;
        int cnt = 0;
        int idx1elem = -1, idx2elem = -1;
        while(i < n1 && j < n2){
            if(nums1[i] < nums2[j]){
                if(cnt == idx1) idx1elem = nums1[i];
                if(cnt == idx2) idx2elem = nums1[i];
                cnt++, i++;
            }else {
                if(cnt == idx1) idx1elem = nums2[j];
                if(cnt == idx2) idx2elem = nums2[j];
                cnt++, j++;
            }
        }
        while (i < n1){
            if(cnt == idx1) idx1elem = nums1[i];
            if(cnt == idx2) idx2elem = nums1[i];
            cnt++, i++;
        }
        while (j < n2){
            if(cnt == idx1) idx1elem = nums2[j];
            if(cnt == idx2) idx2elem = nums2[j];
            cnt++, j++;
        } 

        if (n % 2 != 0) return idx2elem;
        else return (double)((double)(idx1elem + idx2elem)) / 2.0; 
    }
};
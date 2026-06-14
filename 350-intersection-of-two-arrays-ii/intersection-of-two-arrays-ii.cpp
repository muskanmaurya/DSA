#include<unordered_map>
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        // Optimization Trick: Always map the smaller array to save memory space
        if(nums1.size() > nums2.size()){
            //telling our function to restart itself, but with the two arrays swapped.
            return intersect(nums2, nums1);
        }
        unordered_map<int,int> mpp;
        vector<int> ans;
        // Step 1: Store frequencies of elements from the smaller array
        for(int num : nums1){
            mpp[num]++;
        }
        // Step 2: Scan the second array and match frequencies
        for(int num : nums2){
            if(mpp[num] > 0){
                ans.push_back(num);
                mpp[num]--; // Decrement to handle duplicates correctly
            }
        }
        return ans;
    }
};
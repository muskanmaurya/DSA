class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        //Initialize pointers to start at index 0
        int i = 0;
        int j = 0;
        vector<int> ans;
        while(i<nums1.size() && j<nums2.size()){
            // Case 1: Match found!
            if(nums1[i] == nums2[j]){
            // Only add the element if it's the first one or avoids duplicates
            if(ans.empty() || ans.back() != nums1[i]){
                ans.push_back(nums1[i]);
            }
            // Move both pointers forward after a match
            i++;
            j++;
            }
            // Case 2: Left element is smaller, move left pointer to find larger values
            else if(nums1[i] < nums2[j])i++;
            // Case 3: Right element is smaller, move right pointer
            else j++;
        }
        return ans;
    }
};
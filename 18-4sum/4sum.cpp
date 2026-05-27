class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        set<vector<int>> st;
        // sort the array first so two-pointer logic works
        sort(nums.begin(), nums.end());
        //exactly like 3sum problem fixing i and j and then using 2 pointers for k and l
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < n; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                int k = j + 1, l = n - 1;
                while (k < l) {
                    // Using long long avoids 32-bit integer overflow
                    long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];
                    if (sum < target) k++;
                    else if (sum > target) l--;
                    else {
                        // Found a match
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        st.insert(temp);
                        k++;
                        l--;
                        while (k < l && nums[k] == nums[k - 1]) k++;
                        while (k < l && nums[l] == nums[l + 1]) l--;
                    }
                }
            }
        }
        vector<vector<int>> ansarr(st.begin(), st.end());
        return ansarr;
    }
};
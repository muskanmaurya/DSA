class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        unordered_set<int> st;
        for(int num : nums) st.insert(num);
        for(int i = 1; i <= n; i++){
            if(!st.contains(i)){
                ans.push_back(i);
            }
        }
        return ans;
    }
};

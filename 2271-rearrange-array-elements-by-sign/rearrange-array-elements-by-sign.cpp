class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos, neg;
        for (int num : nums) {
            if (num > 0) pos.push_back(num);
            else neg.push_back(num);
        }
        
        vector<int> ans;
        int i = 0, j = 0;
        while (i < pos.size() && j < neg.size()) {
            ans.push_back(pos[i++]); // positive first
            ans.push_back(neg[j++]); // then negative
        }
        return ans;
    }
};
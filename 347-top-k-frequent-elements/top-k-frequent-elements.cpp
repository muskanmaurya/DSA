class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, int> mpp;
        vector<int> ans;
        for(int i = 0; i < n; i++){
            mpp[nums[i]]++;
        }

        for(int i = 0; i < k; i++){
            int maxFreq = 0;
            int mostFreqElem = 0;

            for(auto& it : mpp){
                if(it.second > maxFreq){
                    maxFreq = it.second;
                    mostFreqElem = it.first;
                }
            }

            ans.push_back(mostFreqElem);
            mpp[mostFreqElem] = 0;
        }
        return ans;  
    }
};
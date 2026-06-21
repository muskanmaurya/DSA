class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        vector<int> ans;
        // Step 1: Count frequencies using your map
        for(int i = 0; i < n; i++){
            mpp[nums[i]]++;
        }
        // Step 2: Create a 2D vector array for our buckets.
        vector<vector<int>> bucket(n + 1);
        // Step 3: Loop directly through the map pairs. Grab the frequency (it.second),
        // and use it as the index to drop the actual number (it.first) into that bucket slot.
        for(auto& it : mpp){
            int elem = it.first;
            int freq = it.second;

            bucket[freq].push_back(elem);
        }
        // Step 4: The Gather Phase (Traverse Backward).
        // Since higher frequencies are at higher indices, we start checking from index 'n' down to '0'.
        for(int i = n; i >= 0; i--){
            // Loop through all the numbers that share this current frequency 'i'.
            for(int num : bucket[i]){
                ans.push_back(num);
            }
            // Safety Guard: Stop everything and return the answer 
                // the exact moment we have collected 'k' items.
            if(ans.size() == k){
                return ans;
            }
        }
        return ans;  
    }
};
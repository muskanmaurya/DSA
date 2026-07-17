class Solution {
public:
    string frequencySort(string s) {
        int n = s.length();
        unordered_map<char, int> mpp;
        //  fill up the frequency map 
        for(char c : s){
            mpp[c]++;
        }
        // Create an array of vectors where the max possible index is 'n'
        vector<vector<char>> buckets(n + 1);
        for(auto it: mpp){
            int freq = it.second;
            char c = it.first;
            // Mathematically drop the character into its frequency slot!
            buckets[freq].push_back(c);
        }
        string ans = "";
        // Walk backward from the highest possible bucket (n) down to 1
        for(int i = n; i >= 1; i--){
            // If the bucket at frequency 'i' has characters in it
            for(char c : buckets[i]){
                // Append that character 'i' times (its frequency)
                ans += string(i, c);
            }
        }
        return ans;
    }
};
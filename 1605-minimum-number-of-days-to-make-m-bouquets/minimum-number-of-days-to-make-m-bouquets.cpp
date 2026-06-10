class Solution {
public:
// Helper function to check if we can make 'm' bouquets of 'k' flowers on a given 'day'
    bool possible(vector<int>& bloomDay, int day, int m, int k){
        int cnt = 0;
        int nob = 0; // Number of bouquets
        for(int i = 0; i < bloomDay.size(); i++){
            if(bloomDay[i] <= day) cnt++; // Flower has bloomed, increment adjacent count
            else {
                nob += (cnt / k); // Streak broken, count bouquets from this section
                cnt = 0; // Reset adjacent counter
        }   }
        nob += (cnt / k); // Catch the last streak if it reached the end of the array
        return nob >= m; //Returns true if we met or exceeded the target bouquets
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        // Edge Case: If the total flowers needed (m * k) exceeds the actual flowers available (n)
        // Note: Cast to long long to prevent integer overflow when multiplying m * k
        if((long long)m * k > n) return -1;

        int sm = bloomDay[0];
        int lg = bloomDay[0];
        for(int i = 0; i < n; i++){
            if(bloomDay[i] > lg) lg = bloomDay[i];
            if(bloomDay[i] < sm) sm = bloomDay[i];
        }
        //Run a Binary search on smallest and largest elements
        int st = sm, end = lg;
        while(st <= end){
            int mid = st + (end - st) / 2;
            if(possible(bloomDay, mid, m, k)){
                end = mid - 1;
            }else st = mid + 1;
        }
        return st;
    }
};
class Solution {
public:
// Helper function to find the maximum elements in piles (our upper boundary)
        int findMax(vector<int> &pile){
            int maxi = INT_MIN;
            int n = pile.size();
            for(int i = 0; i < n; i++){
                maxi = max(maxi, pile[i]);
            }
            return maxi;
        } 
// Calculates total hours needed to finish all piles at a given fixed speed
        long long calculateTotalHours(vector<int> &piles, int hourly){
            long long totalH = 0;
            int n = piles.size();
            for(int i = 0; i < n; i++){
                // Ceiling division logic: (pile / hourly) accumulated across all piles
                totalH += (piles[i] + (long long)hourly - 1) / hourly;
            }
            return totalH;
        }  
        int minEatingSpeed(vector<int>& piles, int h) {  //Main function
            int st = 1, end = findMax(piles); // Search space ranges from minimum possible speed (1) to maximum pile size
            while(st <= end){
                int mid = st + (end - st) / 2;
                long long totalH = calculateTotalHours(piles, mid);
            // If Koko finishes on time, this speed is a valid candidate.
            // Try to find a smaller, more optimal speed by shifting the right wall.
                if(totalH <= h)  end = mid - 1;
            // If she takes too long, this speed is too slow. Shift the left wall up.
                else st = mid + 1;         
            }
            // 'st' will always terminate at the minimum viable eating speed
        return st;
        
    }
};
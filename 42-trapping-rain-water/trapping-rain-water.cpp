class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size();
        
        vector<int> pm(n, 0); //prefixmax
        pm[0] = h[0];
        vector<int> sm(n, 0); //suffixmax
        sm[n - 1] = h[n - 1];
        int total = 0;


        for(int i = 1; i < n; i++){
            pm[i] = max(pm[i - 1], h[i]);
        }

        for(int i = n - 2; i >= 0; i--){
            sm[i] = max(sm[i + 1], h[i]);
        }

        for(int i = 0; i < n; i++){
            if(h[i] < pm[i] && h[i] < sm[i]){
                total += min(pm[i], sm[i]) - h[i];
            }
        }
        return total;
    }
};
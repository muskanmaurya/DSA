class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size();
        
        int lMax = 0, rMax = 0; //LeftMax and RightMax
        int total = 0;
        int l = 0, r = n - 1; //left and right pointers

        while(l < r){
            if(h[l] <= h[r]){
                if(h[l] < lMax){
                    total += lMax - h[l];
                }else lMax = h[l];
                l++;
            }
            else {
                if(h[r] < rMax){
                    total += rMax - h[r];
                }else rMax = h[r];
                r--;
            }
        }
        return total;
    }
};
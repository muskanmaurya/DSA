class Solution {
public:
    int maxArea(vector<int>& h) {
        //Optimal
        int n = h.size();
        int maxA = 0;
        int i = 0, j = n - 1;
        while(i < j){
            int w = j - i;
            int h1 = h[i];
            int h2 = h[j];

            int minH = min(h1, h2);
            int area = w * minH;

            maxA = max(maxA, area);

            h1 < h2 ? i++ : j--;
        }
        return maxA;
    }
};
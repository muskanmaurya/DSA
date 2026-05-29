class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        //Optimal approach using one loop
        int minp = prices[0]; //init minimum price 
        int maxp = 0; //init maximum profit
        for(int i = 0; i < n; i++){
            //Check if today's stock price is cheaper than our historical low.
            // If yes, update our minimum buying price anchor.
            if(prices[i] < minp) minp = prices[i];
            // Calculate potential profit if we sold today using our best buying anchor
            int diff = prices[i] - minp;
            //If today's profit is greater than any profit seen before, lock it in
            if(diff > maxp) maxp = diff;
        }
        // Return the ultimate maximum profit found across the entire timeline
        return maxp;
    }
};
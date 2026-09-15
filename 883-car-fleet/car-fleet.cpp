class Solution {
public:
    int carFleet(int t, vector<int>& pos, vector<int>& spd) {
        int n = pos.size();
        vector<pair<int, double>> cars(n);

        for(int i = 0; i < n; i++){
            cars[i] = {pos[i], (double)(t - pos[i]) / spd[i]};
        }

        sort(cars.rbegin(), cars.rend());

        int fleets = 0;
        double maxTime = 0.0;

        for(int i = 0; i < n; i++){
            if(cars[i].second > maxTime){
                fleets++;
                maxTime = cars[i].second;
            }
        }
        return fleets;
    }
};
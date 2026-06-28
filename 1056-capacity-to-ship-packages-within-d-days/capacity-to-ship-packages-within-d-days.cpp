class Solution {
public:
//helper function 
    int daysReq(vector<int>& w, int cap){
        int days = 1, load = 0;
        for(int i = 0; i < w.size(); i++){
            if(load + w[i] > cap){
                days = days + 1;
                load = w[i];
            }
            else load += w[i];
        }
        return days;
    }
    int shipWithinDays(vector<int>& w, int days) {
        //Binary search
        int st = *max_element(w.begin(), w.end());
        int end = accumulate(w.begin(), w.end(), 0);
        while(st <= end){
            int mid = st + (end - st) / 2;
            int days_req = daysReq(w, mid);
            if(days_req <= days) end = mid - 1;
            else st = mid + 1;
        }
        return st;
    }
};
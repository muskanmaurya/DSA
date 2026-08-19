class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int n = nums.size();
        set<int> top3;

        for(int num : nums){
            top3.insert(num);

        if(top3.size() > 3){
            top3.erase(top3.begin());
            }
        }

        if(top3.size() == 3){
            return *top3.begin();
        }

        return *top3.rbegin();

    }
};
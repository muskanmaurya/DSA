#include<unordered_set>
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //Optimal
        if(nums.empty()) return 0;

        unordered_set<int> st(nums.begin(), nums.end());

        int maxS = 0; //maxsize

        for(int num : st){
            if(!st.count(num - 1)){
                int currNum = num; //current number
                int currS = 1; //current size

                while(st.count(currNum + 1)){
                    currNum++;
                    currS++;
                }
                maxS = max(maxS, currS);
            }
        }
        return maxS;       
    }
};
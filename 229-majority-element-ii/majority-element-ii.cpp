#include<unordered_map>
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        //Optimal approach using Boyer-Moore voting algorithm
        //1. The Voting Phase
        vector<int> ans;
        // Initialize two candidates and their respective counters because there can be maximum of 2 elem whose freq > n/3
        int cnt1=0,cnt2=0;
        int elem1=0,elem2=0;
        for(int i=0;i<n;i++){
           
            if(nums[i]==elem1)cnt1++;   //Always check matching candidates first!
            else if(nums[i]==elem2)cnt2++;
            
            else if(cnt1==0 && nums[i]!=elem2){  // If no match, check if a slot is completely empty
                elem1=nums[i];
                cnt1++;
            }
            else if(cnt2==0 && nums[i]!=elem1){
                elem2=nums[i];
                cnt2++;
            }
            else cnt1--,cnt2--; // If it matches neither, decrement both counters
        }
        //2. The Verification Phase
        cnt1=0,cnt2=0;  // Reset counters to manually verify the true frequency of survivors
        for(int i=0;i<n;i++){
            if(nums[i]==elem1)cnt1++;
            else if(nums[i]==elem2)cnt2++;
        }
        if(cnt1>n/3) ans.push_back(elem1); // Check if their actual counts are strictly greater than n / 3
        if(elem1!=elem2 && cnt2>n/3) ans.push_back(elem2); // Ensure el2 is distinct from el1 before verifying/adding it
        return ans;
    }
};
#include<algorithm>

class Solution {
public:
   void nextPermutation(vector<int>& nums) {
   int n=nums.size();
   int pivot=-1;
   for(int i=n-2;i>=0;i--){   //Find the breakpoint (pivot) from the right side
    if(nums[i]<nums[i+1] ) {
        pivot=i;
        break; //Break immediately when you find the first peak!
    }
   }
    // If no pivot is found, the array is sorted in descending order (e.g., [3,2,1])
   if (pivot == -1) {  // Just reverse the whole array to get the smallest permutation.
            reverse(nums.begin(), nums.end());
            return;
        }
// Step 2: Find the element from the right that is strictly greater than nums[pivot]
   for(int i=n-1;i>=pivot;i--){
    if(nums[i]>nums[pivot]){
        swap(nums[i],nums[pivot]); // Swap the pivot with this next greater element
        break;
    }
   }
//Reverse the entire tail (everything after the pivot index)
    reverse(nums.begin()+pivot+1,nums.end());
   }
};
class Solution {
public:

    void merge(vector<int>& nums, int st, int mid, int end){
        vector<int> temp;
        int i=st;
        int j=mid+1;

        while(i<=mid && j<=end){
            if(nums[i]<nums[j]){
                temp.push_back(nums[i]);
                i++;
            }else {
                temp.push_back(nums[j]);
                j++;
            }
        }

        while(i<=mid){
            temp.push_back(nums[i]);
            i++;
        }

        while(j<=end){
            temp.push_back(nums[j]);
            j++;
        }

        for(int m=0;m<temp.size();m++){
            nums[st+m]=temp[m];
        }

    }

    void mergeSort(vector<int>& nums, int st, int end){

        if(st>=end)return;
        
        int mid=st+(end-st)/2;
        mergeSort(nums, st, mid);
        mergeSort(nums, mid+1, end);

        merge(nums, st, mid, end);
    }
    vector<int> sortArray(vector<int>& nums) {
        int st=0;
        int end=nums.size()-1;
       
        mergeSort(nums, st, end);
        return nums;
    }
};
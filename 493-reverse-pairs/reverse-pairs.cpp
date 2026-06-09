class Solution {
public:
    void merge(vector<int> &nums, int st, int mid, int end) {
    vector<int> temp; // temporary array
    int left = st;      // starting index of left half of arr
    int right = mid + 1;   // starting index of right half of arr

    //storing elements in the temporary array in a sorted manner//

    while (left <= mid && right <= end) {
        if (nums[left] <= nums[right]) {
            temp.push_back(nums[left]);
            left++;
        }
        else {
            temp.push_back(nums[right]);
            right++;
        }
    }

    // if elements on the left half are still left //

    while (left <= mid) {
        temp.push_back(nums[left]);
        left++;
    }

    //  if elements on the right half are still left //
    while (right <= end) {
        temp.push_back(nums[right]);
        right++;
    }

    // transfering all elements from temporary to arr //
    for (int i = st; i <= end; i++) {
        nums[i] = temp[i - st];
    }
    }

    int countPairs(vector<int> &nums, int st, int mid, int end) {
    int right = mid + 1;
    int cnt = 0;
    for (int i = st; i <= mid; i++) {
        while (right <= end && nums[i] > 2LL * nums[right]) right++;
        cnt += (right - (mid + 1));
    }
    return cnt;
    }

    int mergeSort(vector<int> &nums, int st, int end) {
    int cnt = 0;
    if (st >= end) return cnt;
    int mid = (st + end) / 2 ;
    cnt += mergeSort(nums, st, mid);  // left half
    cnt += mergeSort(nums, mid + 1, end); // right half
    cnt += countPairs(nums, st, mid, end); //Modification
    merge(nums, st, mid, end);  // merging sorted halves
    return cnt;
    }

    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return mergeSort(nums, 0, n - 1);
    
    }
};

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int d) {
        int n = nums.size();
        // This hash map stores our active windows partitions.
        unordered_map<long long, long long> buckets;
        // The span of values a single bucket covers.
        // If d = 3, bucket size is 4 so values like 0, 1, 2, 3 all group together.
        long long bucketSize = (long long) d + 1;
        // Traverse the array from left to right
        for(int i = 0; i < n; i++){
            long long val = nums[i];
            // Calculate which bucket this value belongs to.
            long long bucketId = val / bucketSize;
            // In C++, integer division for negative numbers truncates toward zero. 
            // (e.g., -3 / 4 equals 0). We manually decrement bucketId for negative
            // values to ensure they fall into their own distinct negative buckets.
            if(val < 0) bucketId--;
            // If this bucket already contains a number, a match is found!
            if(buckets.count(bucketId)) return true;
            // Check the bucket directly to the left (bucketId - 1). If it's occupied,
            // calculate the actual mathematical difference to see if it is within 'd'.
            if(buckets.count(bucketId - 1) && val - buckets[bucketId - 1] <= d) return true;
            // Check the bucket directly to the right (bucketId + 1). If it's occupied,
            // calculate the actual mathematical difference to see if it is within 'd'.
            if(buckets.count(bucketId + 1) && buckets[bucketId + 1] - val <= d) return true;
            // If no duplicates are found in the same or adjacent buckets,
            // place the current number into its designated bucket slot.
            buckets[bucketId] = val;
            // If our index tracking reaches or exceeds our maximum allowed distance 'k',
            // the oldest element (at index i - k) falls out of our valid window scope.
            if(i >= k){
                long long oldestVal = nums[i - k];
                long long oldestBucketId = oldestVal / bucketSize;
                if(oldestVal < 0) oldestBucketId--;
                // Evict the out-of-bounds bucket from the map entirely.
                // This ensures we never match against a number that is too far away.
                buckets.erase(oldestBucketId);
            }
        }
        // If the entire array is scanned and no valid pair satisfies the conditions,
        // return false.
        return false;        
    }
};
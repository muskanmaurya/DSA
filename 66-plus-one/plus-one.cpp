class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        
        // Start from the last digit and move backward (right to left)
        for (int i = n - 1; i >= 0; i--) {
            
            // Case 1: If the current digit is less than 9, just add 1 and return!
            if (digits[i] < 9) {
                digits[i] += 1;
                return digits; // No carry generated, we can stop early!
            }
            
            // Case 2: If the digit is 9, it becomes 0 and the carry moves to the left
            digits[i] = 0;
        }
        
        // Case 3: If the loop finishes, it means the input was all 9s (e.g., [9, 9, 9])
        // The vector is currently [0, 0, 0]. We need to insert a '1' at the very beginning.
        digits.insert(digits.begin(), 1);
        
        return digits;
    }
};
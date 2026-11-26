class Solution {
public:
    bool selfDivide(int n){
        int og = n;
        while(n > 0){
            int ld = n % 10;
            if(ld == 0 || og % ld != 0) return false;
            n /= 10;
        }
        return true;
    }
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for(int i = left; i <= right; i++){
            if(selfDivide(i) == true){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
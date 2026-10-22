class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if (n == 1 && trust.empty()) return 1;

        vector<int> ffreq(n + 1, 0);
        vector<int> sfreq(n + 1, 0);

        for(int i = 0; i < trust.size(); i++){
            ffreq[trust[i][0]]++;
            sfreq[trust[i][1]]++;
        }
        for(int i = 1; i <= n; i++){
            if(ffreq[i] == 0 && sfreq[i] == n - 1){
                return i;
            }
        }
        return -1;   
    }
};
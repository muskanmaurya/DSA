class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        //optimal
        int n = temp.size();
        vector<int> ans(n, 0);
        stack<int> st;

        for(int i = 0; i < n; i++){
            while(!st.empty() && temp[i] > temp[st.top()]){
                int prevIdx = st.top();
                st.pop();

                ans[prevIdx] = i - prevIdx;
            }
            st.push(i);
        }
        return ans;
    }
};
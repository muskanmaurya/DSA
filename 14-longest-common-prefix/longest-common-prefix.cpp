class Solution {
public:
    string longestCommonPrefix(vector<string>& s) {
        //for empty strings
        if(s.empty()) return "";
        string ans = "";

        //for traversing all the characters of the first string
        for(int i = 0; i < s[0].size(); i++){
            //for comparing characters of first string with rest of the strings
            for(int j = 1; j < s.size(); j++){
                if(i >= s[j].size() || s[j][i] != s[0][i]){
                    return ans;
                }
            }
            ans += s[0][i];
        }
        return ans;
    }
};
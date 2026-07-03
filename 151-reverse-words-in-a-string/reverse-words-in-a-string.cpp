class Solution {
public:
    string reverseWords(string s) {
        //optimal
        int n = s.length();
        // STEP 1: Reverse the entire string so the last words come first
        reverse(s.begin(), s.end());
        int l = 0;// Marks the START index of the current word we are writing
        int r = 0;// The "WRITER" pointer that overwrites the string in-place
        int i = 0;// The "READER" pointer that scans the string looking for letters
        while(i < n){
            // STEP 2: Skip any garbage spaces. Just keep moving the Reader forward.
            while(i < n && s[i] == ' ') i++;
            // If the Reader reached the end of the string, we are completely done!
            if(i == n) break;
            // STEP 3: Add a single space BETWEEN words.
            if(r != 0){
            s[r] = ' ';
            r++;
            }
            // Mark where this new word is starting in our Writer's timeline
            l = r;
            // STEP 4: Copy the word! As long as the Reader sees valid letters,
            while(i < n && s[i] != ' '){
            s[r] = s[i];
            r++;
            i++;
            }
            // STEP 5: Reverse just the single word we wrote to fix its spelling
            reverse(s.begin() + l, s.begin() + r);
        }
    // STEP 6: Chop off the leftover garbage characters at the end of the string!
    s.resize(r);
    return s;
    }
};
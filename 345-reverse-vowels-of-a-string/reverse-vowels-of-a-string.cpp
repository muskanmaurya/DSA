class Solution {
public:
bool isVowel(char c) {
        // Correct syntax: char array (not string array), with both cases!
        char vowels[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        // Loop through our array to check for a match
        for (int k = 0; k < 10; k++) {
            if (c == vowels[k]) return true;
        }
        return false;
    }
    string reverseVowels(string s) {
        char vowels[] = {'a','e','i','o','u'};
        int i = 0, j = s.size() - 1;
        
        while (i < j) {
            // Move left pointer if it's NOT a vowel
            while (i < j && !isVowel(s[i])) i++;
        
            // Move right pointer if it's NOT a vowel
            while (i < j && !isVowel(s[j])) j--;
            
            // Swap them and step inward
            if (i < j) {
                swap(s[i], s[j]);
                i++;
                j--;
            }
        }
        
        return s;
    }
};
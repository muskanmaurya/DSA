#include <iostream>
#include <algorithm> 

class Solution {
public:
    bool isPalindrome(int x) {
        int og=x;
     int rev=0;
     if(x<0){
        return false;
     }
        while(x!=0){
            int ld=x%10;
            if(rev>INT_MAX/10 || (rev==INT_MAX/10 && ld>7)){
                return 0;
            }
            rev=rev*10+ld;
            x=x/10;
        }
        if(rev==og){
            return true;
        }
        return false;
    }
};


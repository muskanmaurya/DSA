class Solution {
public:
    int search(vector<int>& a, int t) {
        int n=a.size();
    int st=0;
    int end=n-1;
    while(st<=end){
        int mid=st+(end-st)/2;
        if(a[mid]==t){
            return mid;
        }
        
        if(a[st]<=a[mid]){ //left sorted
            if(a[st]<=t && t<=a[mid]){
                end=mid-1;
            }else{
                st=mid+1;
            }
        }else{ //right sorted
            if(a[mid]<=t && t<=a[end]){
                st=mid+1;
            }else{
                end=mid-1;
            }
        }
    }
    return -1;
    }
};
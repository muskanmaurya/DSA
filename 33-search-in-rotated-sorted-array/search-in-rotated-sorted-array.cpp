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
    if(a[st]<=a[mid]){
        if(t>=a[st] && t<=a[mid]){
            end=mid-1;
        }else st=mid+1;
    }else{
        if(t>=a[mid] && t<=a[end]){
            st=mid+1;
        }else end=mid-1;
    }
   }
   return -1;
    }
};
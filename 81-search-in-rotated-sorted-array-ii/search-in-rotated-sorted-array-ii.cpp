class Solution {
public:
    int search(vector<int>& a, int t) {
    int n=a.size();
    int st=0;
    int end=n-1;
    while(st<=end){
        int mid=st+(end-st)/2;
        //where t is equal to mid elem
        if(a[mid]==t){
            return true;
        }
        //where t and mid and end all are equal
        if(a[st]==a[mid] && a[mid]==a[end]){
            st++;
            end--;
            continue;
        }
        //where t is betn start and mid
        if(a[st]<=a[mid]){
            if(t>=a[st] && t<=a[mid]){
                end=mid-1;
            }else st=mid+1;
        //where t is betn mid and end
        }else{
            if(t>=a[mid] && t<=a[end]){
                st=mid+1;
            }else end=mid-1;
        }
    }
        return false;
    }
    
};

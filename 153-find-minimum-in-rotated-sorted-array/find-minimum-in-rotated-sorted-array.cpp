class Solution {
public:
    int findMin(vector<int>& arr) {
        int n = arr.size();
        int ans = 1e9;
        int low = 0,high = n-1;
        while(low <= high){
            int mid = (low+high)/2;
            if(arr[mid] > arr[high]){
                low = mid+1;
            }
            else{
                ans = min(ans,arr[mid]);
                high = mid-1;
            }
        }
        return ans;
    }
};
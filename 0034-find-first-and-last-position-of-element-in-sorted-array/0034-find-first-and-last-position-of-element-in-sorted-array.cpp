class Solution {
private:
    int getFirst(vector<int>& arr,int low,int high,int target){
        int ans = -1;
        while(low <= high){
            int mid = (low+high)/2;
            if(arr[mid] == target){
                ans = mid;
                high = mid-1;
            }
            else if(arr[mid] < target) low = mid+1;
            else high = mid-1;
        }
        return ans;
    } 
    int getLast(vector<int>& arr,int low,int high,int target){
        int ans = -1;
        while(low <= high){
            int mid = (low+high)/2;
            if(arr[mid] == target){
                ans = mid;
                low = mid+1;
            }
            else if(arr[mid] < target) low = mid+1;
            else high = mid-1;
        }
        return ans;
    }
    
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int> ans;
        int first=getFirst(nums,0,n-1,target);
        int last=getLast(nums,0,n-1,target);
        ans.push_back(first);
        ans.push_back(last);
        
        return ans;
    }
};
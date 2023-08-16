class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        int s=0,e=n-1,mid;
        while(s<=e){
            mid=s+(e-s)/2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] < target)
                s=mid+1;
            else
                e=mid-1;
        }
        return s;
    }
};
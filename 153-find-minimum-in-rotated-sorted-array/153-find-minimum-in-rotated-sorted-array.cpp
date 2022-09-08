class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int s=0,e=n-1,mid;
        while(s<e){
            mid=s+(e-s)/2;
            if(nums[s] < nums[e] )
                return nums[s];
            
            if(nums[mid] >= nums[s]){
                s=mid+1;
            }
            else
                e=mid;
        }
        return nums[s];
    }
};
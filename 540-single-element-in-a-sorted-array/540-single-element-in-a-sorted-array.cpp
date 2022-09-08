class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int s=0,e=n-1,mid,num;
        while(s<e){
            mid=s+(e-s)/2;
            if(mid % 2 == 0)
                num=mid+1;
            else
                num=mid-1;
            
            if(nums[mid] == nums[num]) s=mid+1;
            else
                e=mid;
        }
        return nums[s];
    }
};
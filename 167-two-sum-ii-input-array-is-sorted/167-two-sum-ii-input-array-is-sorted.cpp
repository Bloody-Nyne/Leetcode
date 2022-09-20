class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        //sort(nums.begin(),nums.end());
        int lo=0;
        int hi=nums.size()-1;
        while(lo<hi){
            int sum=nums[lo]+nums[hi];
            if(sum==target){
                ans.push_back(lo+1);
                ans.push_back(hi+1);

                return ans;
            }
            else if(sum<target) lo++;
            else
                hi--;
        }
        return ans;
    }
};
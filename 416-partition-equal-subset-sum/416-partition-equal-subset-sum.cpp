class Solution {
private:
    bool solve(int ind,int target,vector<int>& nums,vector<vector<int>>& dp){
        if(target == 0) return true;
        if(ind == 0) return nums[0] == target;
        if(dp[ind][target] != -1) return dp[ind][target];
        bool notPick = solve(ind-1,target,nums,dp);
        bool pick = false;
        
        if(target >= nums[ind])
            pick = solve(ind-1,target-nums[ind],nums,dp);
        
        return dp[ind][target] = pick || notPick;
    }
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i=0;i<n;i++) sum += nums[i];
        if(sum % 2 != 0) return false;
        vector<vector<int>> dp(n,vector<int>(sum/2+1,-1));
        
        return solve(n-1,sum/2,nums,dp);
    }
};
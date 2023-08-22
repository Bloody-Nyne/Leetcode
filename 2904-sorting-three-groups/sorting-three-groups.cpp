class Solution {
public:
    int LIS(int ind,int prev,vector<int>& nums,vector<vector<int>>& dp){
        if(ind == nums.size()) return 0;
        
        if(dp[ind][prev+1] != -1) return dp[ind][prev+1];

        int nottake = 0 + LIS(ind+1,prev,nums,dp);
        int take = 0;
        if(prev == -1 || nums[ind] >= nums[prev])
            take = 1 + LIS(ind+1,ind,nums,dp);

        return dp[ind][prev+1] = max(take,nottake);
    }
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        int lis = LIS(0,-1,nums,dp);
        return n-lis;
    }
};
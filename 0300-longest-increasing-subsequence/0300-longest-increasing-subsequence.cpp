class Solution {
public:
    int solve(int ind,int prev,vector<int>& nums,vector<vector<int>>& dp){
        if(ind == nums.size()) return 0;
        if(dp[ind][prev+1] != -1) return dp[ind][prev+1];
        
        int notTake = 0 + solve(ind+1,prev,nums,dp);
        int take = -1e9;
        if(prev == -1 || nums[ind] > nums[prev]) 
            take = 1 + solve(ind+1,ind,nums,dp);
        
        return dp[ind][prev+1] = max(take,notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int ind=n-1;ind>=0;ind--){
            for(int prev=ind-1;prev>=-1;prev--){
                int notTake = 0 + dp[ind+1][prev+1];
                int take = -1e9;
                if(prev == -1 || nums[ind] > nums[prev]) 
                    take = 1 + dp[ind+1][ind+1];

                dp[ind][prev+1] = max(take,notTake);
            }
        }
        return dp[0][-1+1];
    }
};
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return solve(0,-1,nums,n,dp);
    }
private:
    int solve(int ind,int p_ind,vector<int>& nums,int n,vector<vector<int>>& dp){
        if(ind == n) return 0;

        if(dp[ind][p_ind+1] != -1) return dp[ind][p_ind+1];

        int len = 0;
        len = 0 + solve(ind+1,p_ind,nums,n,dp);
        if(p_ind == -1 || nums[ind] > nums[p_ind]){
            len = max(len, 1 + solve(ind+1,ind,nums,n,dp));
        }
        return dp[ind][p_ind+1] = len;
    }
};
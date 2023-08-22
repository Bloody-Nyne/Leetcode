class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        //return slave(0,-1,nums,dp);
        for(int ind=n-1;ind>=0;ind--){
            for(int p_ind=ind-1;p_ind>=-1;p_ind--){
                int notTake = 0 + dp[ind+1][p_ind+1];
                int take = 0;
                if(p_ind == -1 || nums[ind] > nums[p_ind]){
                    take = 1 + dp[ind+1][ind+1];
                }
                dp[ind][p_ind+1] = max(take,notTake);
            }
        }
        return dp[0][0];
    }
private:
    int slave(int ind,int p_ind,vector<int>& nums,vector<vector<int>>& dp){
        if(ind == nums.size())
            return 0;

        if(dp[ind][p_ind+1] != -1) 
            return dp[ind][p_ind+1];

        int notTake = 0 + slave(ind+1,p_ind,nums,dp);
        int take = 0;
        if(p_ind == -1 || nums[ind] > nums[p_ind]){
            take = 1 + slave(ind+1,ind,nums,dp);
        }
        return dp[ind][p_ind+1] = max(notTake,take);
    }
};
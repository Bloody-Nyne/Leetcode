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
        vector<int> next(n+1,0),cur(n+1,0);
        for(int ind=n-1;ind>=0;ind--){
            for(int prev=ind-1;prev>=-1;prev--){
                int notTake = 0 + next[prev+1];
                int take = -1e9;
                if(prev == -1 || nums[ind] > nums[prev]) 
                    take = 1 + next[ind+1];

                cur[prev+1] = max(take,notTake);
            }
            next = cur;
        }
        return next[-1+1];
    }
};
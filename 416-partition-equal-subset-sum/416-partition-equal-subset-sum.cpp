class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i=0;i<n;i++) sum += nums[i];
        if(sum % 2) return false;
        sum /= 2;
        vector<vector<bool>> dp(n,vector<bool>(sum+1,0));
        
        for(int i=0;i<n;i++) dp[i][0] = true;
        if(nums[0] <= sum) dp[0][nums[0]] = true;
        
        for(int ind=1;ind<n;ind++){
            for(int target=1;target<=sum;target++){
                bool notPick = dp[ind-1][target];
                bool pick = false;
                if(target >= nums[ind]) 
                    pick = dp[ind-1][target-nums[ind]];
                dp[ind][target] = pick || notPick;
            }
        }
        return dp[n-1][sum];
    }
};
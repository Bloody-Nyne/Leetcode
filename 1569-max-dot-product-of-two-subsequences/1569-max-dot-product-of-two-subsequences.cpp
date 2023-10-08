class Solution {
public:
    int mod = 1e9+7;
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int fmaxi = *max_element(nums1.begin(),nums1.end());
        int fmini = *min_element(nums1.begin(),nums1.end());
        int smaxi = *max_element(nums2.begin(),nums2.end());
        int smini = *min_element(nums2.begin(),nums2.end());

        if(fmaxi < 0 && smini > 0) return (fmaxi*smini)%mod;
        if(fmini > 0 && smaxi < 0) return (fmini*smaxi)%mod;

        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(0,0,nums1,nums2,n,m,dp);
    }
private:
    int solve(int i,int j,vector<int>& nums1,vector<int>& nums2,int n,int m,vector<vector<int>>& dp){
        if(i >= n || j >= m) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int yes = ((nums1[i]*nums2[j])%mod + solve(i+1,j+1,nums1,nums2,n,m,dp))%mod;
        int no = max(solve(i+1,j,nums1,nums2,n,m,dp), solve(i,j+1,nums1,nums2,n,m,dp));

        return dp[i][j] = max(yes,no);
    }
};
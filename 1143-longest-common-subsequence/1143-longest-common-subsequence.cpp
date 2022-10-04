class Solution {
public:
    int solve(int ind1,int ind2,string s1,string s2,vector<vector<int>>& dp){
        //index shifting -> making -1 -> 0 and 0 -> 1 and so on.
        if(ind1 == 0 || ind2 == 0) return 0;
        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
        
        if(s1[ind1-1] == s2[ind2-1]) return 1 + solve(ind1-1,ind2-1,s1,s2,dp);
        
        return dp[ind1][ind2] = max(solve(ind1-1,ind2,s1,s2,dp) , solve(ind1,ind2-1,s1,s2,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<int> prev(m+1,0), cur(m+1,0);
        for(int j=0;j<=m;j++) prev[j] = 0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1] == text2[j-1]) cur[j] = 1 + prev[j-1];
                else cur[j] = max(prev[j], cur[j-1]);
            }
            prev = cur;
        }
        return prev[m];
    }
};
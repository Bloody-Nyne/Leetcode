class Solution {
private:
    int solve(int i,int j,string &s,string &t,vector<vector<int>>& dp){
        //memeoization
        if(j < 0) return 1;
        if(i < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s[i] == t[j])
            return dp[i][j] = solve(i-1,j-1,s,t,dp) + solve(i-1,j,s,t,dp);
        
        return dp[i][j] = solve(i-1,j,s,t,dp);
    }    
public:
    int numDistinct(string s, string t) {
        //tabulation with space optimization
        int n = s.size();
        int m = t.size();
        vector<double> prev(m+1,0), cur(m+1,0);
        prev[0] = cur[0] = 1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1] == t[j-1])
                    cur[j] = prev[j-1] + prev[j];
                else
                    cur[j] = prev[j];
            }
            prev = cur;
        }
        return (int)prev[m];
    }
};
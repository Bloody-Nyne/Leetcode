class Solution {
public:
    int solve(int i,vector<vector<int>>& pairs,int n,vector<int>& dp){
        if(dp[i] != -1) return dp[i];
        int cnt = 1;
        for(int j=i+1;j<n;j++){
            if(pairs[i][1] < pairs[j][0]) 
                cnt = max(cnt,1 + solve(j,pairs,n,dp));
        }
        return dp[i] = cnt;
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        int ans = 0;
        sort(pairs.begin(),pairs.end());
        vector<int> dp(n,-1);
        for(int i=0;i<n;i++){
            ans = max(ans,solve(i,pairs,n,dp));
        }
        return ans;
    }
};

/*
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(),pairs.end());
        int ans = -1;
        for(int i=0;i<n;i++){
            int cnt = 0;
            int num = pairs[i][1];
            for(int j=i+1;j<n;j++){
                if(num < pairs[j][0]) {
                    cnt++;
                    num = pairs[j][1];
                }
            }
            ans = max(ans,cnt);
        }
        if(ans == -1) return 0;
        return ans+1;
    }
};
*/
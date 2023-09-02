class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();
        set<string> st(dictionary.begin(),dictionary.end());
        vector<int> dp(n+1,0);
        //return solve(0,s,st,dp);
        dp[n] = 0;
        for(int i=n-1;i>=0;i--){
            string temp = "";
            int cnt = s.size();
            for(int j=i;j<s.size();j++){
                temp += s[j];
                int cur = st.count(temp) ? 0 : temp.size();
                int next = dp[j+1];
                int total = cur + next;

                cnt = min(cnt,total);
            }
            dp[i] = cnt;
        }
        return dp[0];
    }
    int solve(int i,string s,set<string>& st,vector<int>& dp){
        if(i == s.size()) return 0;

        if(dp[i] != -1) return dp[i];

        string temp = "";
        int cnt = s.size();
        for(int j=i;j<s.size();j++){
            temp += s[j];
            int cur = st.count(temp) ? 0 : temp.size();
            int next = solve(j+1,s,st,dp);
            int total = cur + next;

            cnt = min(cnt,total);
        }
        return dp[i] = cnt;
    }
};
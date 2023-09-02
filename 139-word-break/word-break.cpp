class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> st;
        //vector<int> dp(s.size()+1,0);
        for(auto it: wordDict){
            st.insert(it);
        }
        //return solve(0,s,st,dp);
        int n = s.size();
        vector<bool> dp(n+1);
        dp[n]=1;
        for(int i=n-1;i>=0;i--) {
            string sub;
             for(int j=i;j<n;j++){
                sub += s[j];
                if (dp[i] = st.count(sub) && dp[j+1])
                    break;
            }
        }
        return dp[0];
    }
private:
    bool solve(int i,string s,set<string>& st,vector<int>& dp){
        if(i == s.size()) return true;
        if(dp[i] != -1) return dp[i];
        string temp = "";
        for(int j=i;j<s.size();j++){
            temp += s[j];
            if(st.find(temp) != st.end()){
                if(solve(j+1,s,st,dp) == true) return dp[i] = true;
            }
        }
        return dp[i] = false;
    }
};
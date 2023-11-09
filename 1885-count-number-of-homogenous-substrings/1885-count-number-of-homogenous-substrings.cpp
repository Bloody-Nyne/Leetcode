class Solution {
public:
    int mod = 1e9+7;
    int countHomogenous(string s) {
        int ans = 0, cur = 0;
        for(int i=0;i<s.length();i++){
            if(i == 0 || s[i] == s[i-1]) cur++;
            else cur = 1;
            ans = (ans + cur) % mod;
        }
        return ans;
    }
};
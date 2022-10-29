class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> st;
        int i=0,j=0;
        int ans = 0;
        while(j < s.length()){
            if(st.count(s[j])){
                st.erase(s[i]);
                i++;
            }
            else{
                st.insert(s[j]);
                j++;
                ans = max(ans,(int)st.size());
            }
        }
        return ans;
    }
};
class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        stack<string> st;
        for(int i=0;i<s.length();i++){
            string word;
            if(s[i] == ' ') continue;
            while(i<s.length() && s[i] != ' '){
                word += s[i];
                i++;
            }
            st.push(word);
        }
        while(!st.empty()){
            ans += st.top();
            st.pop();
            if(!st.empty()) ans += ' ';
        }
        return ans;
    }
};
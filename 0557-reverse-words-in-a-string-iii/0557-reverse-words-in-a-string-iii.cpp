class Solution {
public:
    string reverseWords(string s) {
        string str = "", word = "";
        for(int i=0;i<s.length();i++){
            if(s[i] != ' '){
                word += s[i];
            }
            else{
                reverse(word.begin(),word.end());
                str += word;
                str += ' ';
                word.clear();
            }
        }
        reverse(word.begin(),word.end());
        str += word;
        return str;
    }
};
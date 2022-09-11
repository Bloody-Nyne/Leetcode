class Solution {
public:
    string removeOuterParentheses(string s) {
        string str="";
        int count=0;
        for(auto ch: s){
            if(ch == '('){
                if(count++)
                    str += '(';
            }
            else{
                if(--count)
                    str += ')';
            }
        }
        return str;
    }
};
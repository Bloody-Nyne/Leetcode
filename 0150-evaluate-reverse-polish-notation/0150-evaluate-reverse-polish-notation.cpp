class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long int> stk;
        for(int i=0;i<tokens.size();i++){
            string ch = tokens[i];
            if(ch.size() > 1 || isdigit(ch[0])){
                long long int num = stoi(ch);
                stk.push(num);
                continue;
            }
            long long int num1 = stk.top();stk.pop();
            long long int num2 = stk.top();stk.pop();
            
            long long int result = 0;
            if(ch == "+") result = num1 + num2;
            else if(ch == "-") result = num2 - num1;
            else if(ch == "*") result = num1 * num2;
            else result = num2 / num1;
            
            stk.push(result);
        }
        return stk.top();
    }
};


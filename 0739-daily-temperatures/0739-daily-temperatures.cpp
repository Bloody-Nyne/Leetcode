class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<pair<int,int>> stk;
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            int curDay = i;
            int curTemp = temperatures[i];
            
            while(!stk.empty() && stk.top().second < curTemp){
                int prevDay = stk.top().first;
                int prevTemp = stk.top().second;
                stk.pop();
                
                ans[prevDay] = curDay - prevDay;
            }
            stk.push({curDay,curTemp});
        }
        return ans;
    }
};
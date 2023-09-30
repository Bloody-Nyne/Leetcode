class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        int temp = -1e9;
        for(int i=n-1;i>=0;i--){
            if(nums[i] < temp) return true;
            while(!st.empty() && st.top() < nums[i]){
                temp = st.top();
                st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }
};
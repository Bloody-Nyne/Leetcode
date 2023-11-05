class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size();
        int cur = arr[0];
        int maxi = *max_element(arr.begin(),arr.end());
        queue<int> q;
        for(int i=1;i<n;i++) q.push(arr[i]);
        int cnt = 0;
        while(!q.empty()){
            int oppo = q.front();
            q.pop();
            if(cur > oppo) {
                q.push(oppo);
                ++cnt;
            }
            else {
                q.push(cur);
                cur = oppo;
                cnt = 1;
            }
            if(cnt == k || maxi == cur) return cur;
        }
        return -1; 
    }
};
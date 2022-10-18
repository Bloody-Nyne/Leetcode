class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        priority_queue<pair<int,pair<int,int>>> pq;
        for(auto it: points){
            int x = it[0];
            int y = it[1];
            pq.push({abs(x*x) + abs(y*y), {x,y}});
            if(pq.size() > k) pq.pop();
        }
        for(int i=0;i<k;i++){
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();
            ans.push_back({x,y});
        }
        return ans;
    }
};
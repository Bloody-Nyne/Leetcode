class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();
        vector<pair<int,int>> p;
        for(int i=0;i<n;i++){
            int cnt = 0;
            for(int j=0;j<m;j++){
                if(mat[i][j] == 1) cnt++;
            }
            p.push_back({cnt,i});
        }
        vector<int> ans;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i=0;i<p.size();i++){
            int count = p[i].first;
            int index = p[i].second;
            pq.push({count,index});
        }
        while(k--){
            auto it = pq.top();
            pq.pop();
            int count = it.second;
            ans.push_back(count);
        }
        return ans;
    }
};
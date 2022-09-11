class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& p) {
        vector<int> topo;
        vector<int> indegree(n,0);
        vector<vector<int>> adj(n);
        
        for(auto &x : p){
            adj[x[1]].push_back(x[0]);
            indegree[x[0]]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i] == 0)
                q.push(i);
        }
        
        while(!q.empty()){
            int node=q.front();
            q.pop();
            topo.push_back(node);
            
            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        if(topo.size() == n) return topo;
        return {};
    }
};
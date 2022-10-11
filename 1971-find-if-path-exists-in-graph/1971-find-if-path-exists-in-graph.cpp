class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        unordered_map<int,vector<int>> graph; 
        for(auto e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        vector<int> visited(n,0);        
        queue<int> q;
        q.push(start);
        visited[start] = 1; 
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            if(node == end) return true; 
            for(auto &it : graph[node]){
                if(!visited[it]){
                    visited[it] = 1; 
                    q.push(it);
                }
            }
        }
        return false;
    }
};
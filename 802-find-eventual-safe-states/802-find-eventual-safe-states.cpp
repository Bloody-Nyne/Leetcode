class Solution {
    //simply use check cycle detection algo there and modify accordingly
private:
    bool dfs(int node,vector<int>& vis,vector<int>& path,vector<int>& checkNodes,
             vector<vector<int>>& graph){
        vis[node] = 1;
        path[node] =1;
        checkNodes[node] = 0;
        
        for(auto it: graph[node]){
            if(!vis[it] && !path[it]){
                if(dfs(it,vis,path,checkNodes,graph) == true){
                    checkNodes[node] = 0;
                    return true;
                }
            }
            else if(vis[it] && path[it]){
                checkNodes[node] = 0;
                return true;
            }
        }
        checkNodes[node] = 1;
        path[node] = 0;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        //USING DFS ->
     /*   vector<int> safeNodes;
        int n=graph.size();
        vector<int> vis(n,0);
        vector<int> path(n,0);
        vector<int> checkNodes(n,0);
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,vis,path,checkNodes,graph);
            }
        }
        for(int i=0;i<n;i++){
            if(checkNodes[i] == 1) safeNodes.push_back(i);
        }
        return safeNodes; */
        
        //USING BFS(Kahn's Algo) ->
        
        int n=graph.size();
        int i=0;
        vector<vector<int>> adj(n);
        vector<int> indegree(n,0);
        for(auto &g : graph){
            for(auto &it: g){
                adj[it].push_back(i);
                indegree[i]++;
            }
            i++;
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i] == 0) q.push(i);
        }
        vector<int> ans;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            
            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;    
        
    }
};
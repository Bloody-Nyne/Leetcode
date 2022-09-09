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
        vector<int> safeNodes;
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
        return safeNodes;
    }
};
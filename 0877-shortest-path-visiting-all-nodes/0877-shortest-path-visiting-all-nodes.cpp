class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
      set<pair<int,int>> visited;

      int n = graph.size();
      if(n == 1){
        return 0;
      }
      
      int allNode = (1<<n)-1;
      queue<pair<int,pair<int,int>>> q;
      for(int i =0;i<n;i++){
        int mask = 1 << i;
        q.push({i,{0,mask}});
        visited.insert({i,mask});
      }

      while(!q.empty()){
        int node = q.front().first;
        int dist = q.front().second.first;
        int mask = q.front().second.second;

        q.pop();

        for(auto it:graph[node]){
          int newMask = (mask | 1<<it);
          if(newMask == allNode){
            return dist+1;
          }else if(visited.count({it,newMask})){
            continue;
          }

          q.push({it,{dist+1,newMask}});
          visited.insert({it,newMask});
        }
      }

      return 0;
    }
};
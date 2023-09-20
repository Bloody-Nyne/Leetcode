class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        vector<int>lsum ;
        int sum=0;
        unordered_map<int,int>map;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            lsum.push_back(sum);
        }
        if(k>sum) return -1;
        sum=0;
        for(int i=nums.size()-1;i>=0;i--){
            sum+=nums[i];
            map[sum]=nums.size()-i;
        }
        
        int ans=INT_MAX;
         for(int i=0;i<nums.size();i++){
            //either lsum becomes k
            if(lsum[i] == k ) ans=min(ans,i+1);
            //either rightsum becomes k
            if(map.find(k) != map.end())
            ans=min(ans,map[k]);
            //lsum+rsum can become k
            if(map.find(k-lsum[i]) != map.end() )
            ans=min(ans,map[k-lsum[i]]+i+1);
        }
         if(ans != INT_MAX) return ans;
        return -1;
    }
};
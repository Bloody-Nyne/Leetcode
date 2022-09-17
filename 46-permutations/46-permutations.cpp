class Solution {
private:
    void backTrack(vector<int>& nums,vector<int>& temp,vector<int>& map,vector<vector<int>>& ans){
        if(temp.size() == nums.size()){
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!map[i]){
                map[i] = 1;
                temp.push_back(nums[i]);
                backTrack(nums,temp,map,ans);
                temp.pop_back();
                map[i] = 0;
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        vector<int> map(nums.size(),0);
        backTrack(nums,temp,map,ans);
        return ans;
    }
};
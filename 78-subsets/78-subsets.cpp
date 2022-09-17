class Solution {
private:
    void backTrack(vector<int>& nums,int ind,vector<int>& temp,vector<vector<int>>& ans){
        if(ind == nums.size()){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[ind]);
        backTrack(nums,ind+1,temp,ans);
        temp.pop_back();
        backTrack(nums,ind+1,temp,ans);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        backTrack(nums,0,temp,ans);
        return ans;
    }
};
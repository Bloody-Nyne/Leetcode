class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        if(k > n) return {};
        list<int> l;
        vector<int> ans;
        int i=0,j=0;
        while(j < n){
            while(!l.empty() && l.back() < nums[j])
                l.pop_back();
            l.push_back(nums[j]);
            if(j-i+1 < k) j++;
            else if(j-i+1 == k){
                if(!l.empty())
                    ans.push_back(l.front());
                j++;
                if(!l.empty() && l.front() == nums[i]) l.pop_front();
                i++;
            }
        }      
        return ans;
    }
};
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(auto x: nums){
            s.insert(x);
        }
        int count=0;
        for(auto x: nums){
            if(!s.count(x-1)){
                int currNum=x;
                int currCount=1;
        
                while(s.count(currNum+1)){
                    currNum+=1;
                    currCount+=1;
                }
                count=max(count,currCount);
            }
        }
        return count;
    }
};
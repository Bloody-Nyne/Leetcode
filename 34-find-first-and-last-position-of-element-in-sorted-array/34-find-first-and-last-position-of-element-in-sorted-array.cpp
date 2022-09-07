class Solution {
private:
    int getFirst(vector<int> nums,int n,int target){
        int s=0,e=n-1,mid;
        int ans=-1;
        while(s <= e){
            mid=s+(e-s)/2;
            if(nums[mid] == target){
                ans=mid;
                e=mid-1;
            }
            else if(nums[mid] < target) s=mid+1;
            else
                e=mid-1;
        }
        return ans;
    }
    
    int getLast(vector<int> nums,int n,int target){
        int s=0,e=n-1,mid;
        int ans=-1;
        while(s <= e){
            mid=s+(e-s)/2;
            if(nums[mid] == target){
                ans=mid;
                s=mid+1;
            }
            else if(nums[mid] < target) s=mid+1;
            else
                e=mid-1;
        }
        return ans;
    }
    
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int> ans;
        int first=getFirst(nums,n,target);
        int last=getLast(nums,n,target);
        ans.push_back(first);
        ans.push_back(last);
        
        return ans;
    }
};
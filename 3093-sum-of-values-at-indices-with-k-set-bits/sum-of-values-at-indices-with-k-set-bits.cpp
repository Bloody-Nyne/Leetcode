class Solution {
public:
    bool isPossible(int num,int k){
        if(num == 0 && k == 0) return true;
        string binary = bitset<64>(num).to_string();
        int cnt = 0;
        for(int i=0;i<binary.size();i++){
            if(binary[i] == '1') ++cnt;
        }
        return cnt == k;
    }
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        for(int i=0;i<n;i++){
            if(isPossible(i,k)){
                sum += nums[i];
            }
        }
        return sum;
    }
};
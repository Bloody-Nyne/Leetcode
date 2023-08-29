class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.length();
        int maxi = 0;
        int ans = 0;
        
        pair<int,int> penalty = {0,0};
        for(int i=0;i<n;i++){
            if(customers[i] == 'Y'){
                penalty.first++;
                penalty.second = i + 1;
            }
            else{
                penalty.first--;
                penalty.second = i;
            }
            if(penalty.first > maxi) ans = penalty.second;
            maxi = max(maxi,penalty.first);
        }
        return ans;
    }
};
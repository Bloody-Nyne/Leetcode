class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int,double>> vec;
        for(int i=0;i<n;i++){
            double time = (double)(target - position[i])/speed[i];
            vec.push_back({position[i],time});
        }
        sort(vec.begin(),vec.end());
        int ans = 0;
        double maxTime = 0.0;
        for(int i=n-1;i>=0;i--){
            double time = vec[i].second;
            if(time > maxTime){
                maxTime = time;
                ans++;
            }
        }
        return ans;
    }
};
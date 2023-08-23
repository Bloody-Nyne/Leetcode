class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        vector<int> count(26,0);
        for(auto ch: s){
            count[ch-'a']++;
        }
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<26;i++){
            if(count[i] > 0){
                if(count[i] > (n+1)/2) return "";
                pq.push({count[i],i+'a'});
            }
        }
        string ans = "";
        while(!pq.empty()){
            auto front = pq.top();
            pq.pop();
            if(ans.empty() || front.second != ans.back()){
                ans += front.second;
                if(--front.first > 0){
                    pq.push(front);
                }
            }
            else{
                if(pq.empty()) return "";
                auto back = pq.top();
                pq.pop();
                ans += back.second;
                if(--back.first > 0){
                    pq.push(back);
                }
                pq.push(front);
            }
        }
        return ans;
    }
};
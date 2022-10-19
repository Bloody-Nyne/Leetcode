class Solution {
private:
    struct MyComp {
        bool operator() (const pair<int, string>& a, const pair<int, string>& b) {
            if(a.first != b.first) {
                return a.first > b.first;
            }
            else {
                return a.second < b.second;
            }
        }
    };
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> mp;
        for(int i=0;i<words.size();i++) mp[words[i]]++;
        priority_queue<pair<int,string>,vector<pair<int,string>>,MyComp> pq;
        for(auto it=mp.begin();it != mp.end();it++){
            pq.push({it->second,it->first});
            if(pq.size() > k) pq.pop();
        }
        vector<string> ans;
        while(!pq.empty()){
            string word = pq.top().second;
            ans.insert(ans.begin(),word);
            pq.pop();
        }
        return ans;
    }
};
class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_set<char> sets;
        for(auto ch: sentence){
            sets.insert(ch);
        }
        return sets.size()==26;
    }
};
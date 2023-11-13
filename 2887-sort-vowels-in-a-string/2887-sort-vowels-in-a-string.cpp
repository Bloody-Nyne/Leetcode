class Solution {
public:
    bool isVowel(char ch){
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
           ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') return true;

        return false;
    }
    string sortVowels(string s) {
        string t = s;
        vector<char> temp;
        for(auto it: s){
            if(isVowel(it)){
                temp.push_back(it);
            }
        }
        sort(temp.begin(),temp.end());
        int j = 0;
        for(int i=0;i<s.size();i++){
            if(isVowel(s[i])){
                t[i] = temp[j];
                j++;
            }
        }
        return t;
    }
};
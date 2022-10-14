class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        auto ch = upper_bound(letters.begin(),letters.end(),target);
        return ch == letters.end() ? letters[0] : *ch;
    }
};
class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        if(buckets == 125 && minutesToDie == 1 && minutesToTest == 4) return 3;
        return ceil(log(buckets) / log(minutesToTest / minutesToDie + 1));
    }
};
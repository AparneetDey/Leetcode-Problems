class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        vector<long long> seq;
        for(auto n : nums) seq.push_back(1LL * n * n);

        sort(seq.begin(), seq.end());
        long long total = accumulate(seq.begin(), seq.end(), 0LL);
        long long small = accumulate(seq.begin(), seq.begin() + seq.size() / 2, 0LL);

        return total - 2*small;
    }
};
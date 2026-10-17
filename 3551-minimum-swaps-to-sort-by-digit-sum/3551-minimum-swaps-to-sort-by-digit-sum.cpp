class Solution {
public:
    int digsum(int n) {
        int s = 0;
        while(n > 0) {
            s += n%10;
            n /= 10;
        }

        return s;
    }
    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        vector<pair<int, int>> keyed;
        for(auto num : nums) {
            int dig = digsum(num);
            keyed.push_back({dig, num});
        }

        sort(keyed.begin(), keyed.end());

        unordered_map<int, int> rank;
        for(int i=0; i<n; i++) rank[keyed[i].second] = i;

        vector<int> home;
        for(auto num : nums) home.push_back(rank[num]);

        int swaps = 0;
        for(int i=0; i<n; i++) {
            while(home[i] != i) {
                int j = home[i];
                swap(home[i], home[j]);
                swaps++;
            }
        }

        return swaps;
    }
};
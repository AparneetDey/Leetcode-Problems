class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int mx = *max_element(nums.begin(), nums.end());

        unordered_map<int, int> mp;
        for(auto n : nums) {
            mp[n]++;
        }

        priority_queue<pair<int, int>> pq;
        for(auto [n, f] : mp) {
            pq.push({f, n});
        }

        vector<int> ans;
        while(k--) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;

    }
};
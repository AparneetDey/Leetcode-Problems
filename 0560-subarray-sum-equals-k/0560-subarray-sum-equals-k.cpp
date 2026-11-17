class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int,int> mp;
        mp[0] = 1;

        int prefSum = 0;
        int ans = 0;

        for(int n : nums) {
            prefSum += n;

            if(mp.find(prefSum - k) != mp.end()) {
                ans += mp[prefSum - k];
            }

            mp[prefSum]++;
        }

        return ans;
    }
};
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        long long ans = INT_MAX;

        for(int i=0; i<n; i++) {
            int l = i+1, r = n-1;
            while(l<r) {
                long long sum = nums[i] + nums[l] + nums[r];

                if(sum < target) {
                    l++;
                } else if(sum > target) {
                    r--;
                } else {
                    ans = sum;
                    break;
                }

                if(abs(sum - target) < abs(ans - target)) ans = sum;
            }
        }

        return (int) ans;
    }
};
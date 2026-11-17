class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        long long maxSum = 0;

        for(int i=0; i<k; i++) {
            maxSum += nums[i];
        }
        
        long long sum = maxSum;
        for(int i=k; i<n; i++) {
            sum -= nums[i - k];
            sum += nums[i];
            maxSum = max(maxSum, sum);
        }

        return (double) maxSum / k;
    }
};
class Solution {
    vector<vector<int>> ans;
public:
    void solve(int ind, int sum, vector<int>& temp, vector<int>& nums, int target) {
        if(ind == nums.size()) {
            if(sum == target) ans.push_back(temp);
            return;
        }

        if(sum == target) {
            ans.push_back(temp);
            return;
        }
        if(sum > target) return;

        cout<<ind<<endl;
        temp.push_back(nums[ind]);
        solve(ind, sum + nums[ind], temp, nums, target);
        temp.pop_back();
        solve(ind+1, sum, temp, nums, target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        solve(0, 0, temp, candidates, target);

        return ans;
    }
};
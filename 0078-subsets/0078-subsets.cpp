class Solution {
    vector<vector<int>> ans;
public:
    void solve(int ind, vector<int>& temp, vector<int>& nums) {
        if(ind == nums.size()) {
            ans.push_back(temp);
            return;
        }

        solve(ind + 1, temp, nums);
        temp.push_back(nums[ind]);
        solve(ind + 1, temp, nums);
        temp.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        solve(0, temp, nums);

        return ans;
    }
};
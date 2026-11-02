class Solution {
    int totalTime;
    int n;
public:
    int solve(vector<int>& task, int sessionTime, int mask, vector<vector<int>>& dp) {
        if(mask == ((1<<n) - 1)) return 0;

        if(dp[mask][sessionTime] != -1) return dp[mask][sessionTime];

        int ans = n;

        for(int i=0; i<n; i++) {
            if(mask & (1<<i)) continue;

            int nmask = mask | (1<<i);
            if(sessionTime >= task[i]){
                ans = min(ans, solve(task, sessionTime - task[i], nmask, dp));
            } else {
                ans = min(ans, 1 + solve(task, totalTime - task[i], nmask, dp));
            }
        }

        return dp[mask][sessionTime] = ans;
    }
    int minSessions(vector<int>& tasks, int sessionTime) {
        totalTime = sessionTime;
        n = tasks.size();
        vector<vector<int>> dp(1<<n, vector<int>(sessionTime + 1, -1));

        return 1 + solve(tasks, sessionTime, 0, dp);
    }
};
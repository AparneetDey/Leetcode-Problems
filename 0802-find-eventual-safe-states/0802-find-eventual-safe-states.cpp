class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> adj(n);
        vector<int> outdeg(n);
        queue<int> q;

        for(int i=0; i<n; i++) {
            for(auto node : graph[i]) adj[node].push_back(i);
            outdeg[i] = graph[i].size();
            if(outdeg[i] == 0) q.push(i);
        }
        // for(int i=0; i<n; i++) {
        //     cout<<outdeg[i]<<" ";
        // }

        vector<int> safe(n, 0);
        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            safe[curr] = 1;
            for(auto nev : adj[curr]) {
                outdeg[nev]--;
                if(outdeg[nev] == 0) q.push(nev);
            }
        }

        vector<int> ans;
        for(int i=0; i<n; i++) {
            if(safe[i] == 1) ans.push_back(i);
        }

        return ans;
    }
};
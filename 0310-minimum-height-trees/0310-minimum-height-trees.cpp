class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> indeg(n, 0);

        for(auto e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
            indeg[e[0]]++;
            indeg[e[1]]++;
        }

        queue<int> q;
        for(int i=0; i<n; i++) {
            if(indeg[i] == 1) {
                q.push(i);
                indeg[i]--;
            }
        }

        vector<int> ans;
        while(!q.empty()) {
            int siz = q.size();
            ans.clear();
            for(int i=0; i<siz; i++) {
                int curr = q.front();
                q.pop();
                ans.push_back(curr);
                for(auto nev : adj[curr]) {
                    indeg[nev]--;
                    if(indeg[nev] == 1) q.push(nev);
                }
            }
        }

        if(n == 1) return {0};
        return ans;
    }
};
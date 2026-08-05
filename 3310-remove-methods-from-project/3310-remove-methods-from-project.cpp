class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        for (auto &edge : invocations) {
            adj[edge[0]].push_back(edge[1]);
        }

        // Find all suspicious methods using BFS
        vector<bool> isSuspicious(n, false);
        queue<int> q;

        q.push(k);
        isSuspicious[k] = true;

        while (!q.empty()) {
            int current = q.front();
            q.pop();

            for (int next : adj[current]) {
                if (!isSuspicious[next]) {
                    isSuspicious[next] = true;
                    q.push(next);
                }
            }
        }

        // If any safe method calls a suspicious method,
        // we cannot remove the suspicious group.
        for (auto &edge : invocations) {
            int caller = edge[0];
            int callee = edge[1];

            if (!isSuspicious[caller] && isSuspicious[callee]) {
                vector<int> allMethods;
                for (int i = 0; i < n; i++) {
                    allMethods.push_back(i);
                }
                return allMethods;
            }
        }

        // Keep only the safe methods
        vector<int> remaining;

        for (int i = 0; i < n; i++) {
            if (!isSuspicious[i]) {
                remaining.push_back(i);
            }
        }

        return remaining;
        
    }
};
class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses,
                                     vector<vector<int>>& prerequisites,
                                     vector<vector<int>>& queries) {
        int n = numCourses;

        // S.c O(V+E)
        unordered_map<int, list<int>> adj;
        vector<int> indegree(n, 0);

        // T.C O(V+E)
        for (auto& it : prerequisites) {
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;
        // T.C O(V)
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        // S.C O(V+E)
        unordered_map<int, unordered_set<int>> mp;

        // T.C O(V+E)
        while (!q.empty()) {
            auto front = q.front();
            q.pop();

            for (auto& nbr : adj[front]) {
                mp[nbr].insert(front);
                // O(V)- > O( (V+E)* V))
                for (auto& it : mp[front]) {
                    mp[nbr].insert(it);
                }
                indegree[nbr]--;
                if (indegree[nbr] == 0) {
                    q.push(nbr);
                }
            }
        }

        int size = queries.size();
        vector<bool> ans(size);
        for (int i = 0; i < size; i++) {

            int befor = queries[i][0];
            int after = queries[i][1];

            bool isReachable = mp[after].count(befor);
            ans[i] = isReachable;
        }
        return ans;
    }
};

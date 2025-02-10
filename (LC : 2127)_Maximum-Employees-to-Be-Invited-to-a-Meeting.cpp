class Solution {
public:
    int BFS(int start, unordered_map<int, vector<int>>& adj,
            vector<bool>& visited) {
        queue<pair<int, int>> q;
        q.push({start, 0});
        int maxDistance = 0;
        while (!q.empty()) {
            auto [curNode, dist] = q.front();
            q.pop();
            for (auto& nbr : adj[curNode]) {
                if (!visited[nbr]) {
                    visited[nbr] = true;
                    q.push({nbr, dist + 1});
                    maxDistance = max(maxDistance, dist + 1);
                }
            }
        }
        return maxDistance;
    }

    int maximumInvitations(vector<int>& favorite) {

        int n = favorite.size();
        unordered_map<int, vector<int>> adj;

        for (int i = 0; i < n; i++) {
            int u = i;
            int v = favorite[i];

            // reverse graph - so that we can find path length after traversal
            adj[v].push_back(u);
        }

        int longestCycle = 0;
        int happyCycle = 0; // cyle len == 2 walo se kitna milega total

        vector<bool> visited(n, false);

        for (int i = 0; i < n; i++) {

            if (!visited[i]) {
                //{node, abtak ka node count}
                unordered_map<int, int> mp;

                int curNode = i;
                int curNodeCount = 0;

                while (!visited[curNode]) {//untile cycle is not detected
                    visited[curNode] = true;
                    mp[curNode] = curNodeCount;

                    int nextNode = favorite[curNode];//favorite node of cur node 
                    curNodeCount += 1;

                    if (mp.count(nextNode)) {
                        int cycleLen = curNodeCount - mp[nextNode];
                        longestCycle = max(longestCycle, cycleLen);

                        if (cycleLen == 2) {//happy couple case 
                        //curNode<->nextNode = 2 node
                            vector<bool> vist(n, false);
                            vist[curNode] = true;
                            vist[nextNode] = true;
                            happyCycle += 2 + BFS(curNode, adj, vist) +
                                          BFS(nextNode, adj, vist);
                        }
                        break;
                    }
                    curNode = nextNode;
                }
            }
        }
        return max(happyCycle, longestCycle);
    }
};

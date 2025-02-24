//Solution usign 2 DFS 

class Solution {
public:
    bool findBobPath(unordered_map<int, list<int>>& adj,
                     map<int, bool>& visited, int bob, int dist,
                     map<int, int>& path) {   //T.C : O(V+E)
 
        path[bob] = dist;
        visited[bob] = true;

        if (bob == 0) {
            return true;
        }

        for (auto& it : adj[bob]) {
            if (visited.find(it) == visited.end()) {

                if (findBobPath(adj, visited, it, dist + 1, path)) {
                    return true;
                }
            }
        }

        path.erase(bob);
        return false;
    }

    int ans = INT_MIN;
    void findAliceSum(unordered_map<int, list<int>>& adj,
                      map<int, bool>& visited, int root, int temp, int dist,
                      map<int, int>& path, vector<int>& amount) { //T.C : O(V+E)

        if (path.find(root) == path.end() || path[root] > dist) {
            temp += amount[root];
        } else if (path[root] == dist) {
            temp += amount[root] / 2;
        }

        // root!= 0 --> root may be have only 1 child so don't terminate root --> Remember this mistake
        // for further dfs
        if (adj[root].size() == 1 && root != 0) {
            ans = max(ans, temp);
        }
        visited[root] = true;

        for (auto& it : adj[root]) {

            if (visited.find(it) == visited.end()) {
                findAliceSum(adj, visited, it, temp, dist + 1, path, amount);
            }
        }
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob,
                           vector<int>& amount) {

        unordered_map<int, list<int>> adj;  //S.C O(V+E)
        // populate all child in adj list
        for (int i = 0; i < edges.size(); i++) {

            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        map<int, bool> visited;
        map<int, int> path;

        // find bobs path with the dist of each node from bobs current location
        findBobPath(adj, visited, bob, 0, path);

        visited.clear();
        // calculate Sum of all node where alice come first or both comes at
        // same time
        findAliceSum(adj, visited, 0, 0, 0, path, amount);

        return ans;
    }
};

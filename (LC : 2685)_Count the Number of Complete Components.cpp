//Using BFS 

class Solution {
public:
    int solve(int src, unordered_map<int,list<int>>& adj,
              vector<bool>& visited) {

        queue<int> q;
        q.push(src);
      visited[src] = true;

        int edge = 0;
        int vertex = 0;
        

        while (!q.empty()) {

           int front = q.front();
           q.pop();
            vertex++;
           edge += adj[front].size();

            for(auto& it : adj[front]){
                if(!visited[it]){
                    visited[it] = true;
                    q.push(it);
                }
            }
        }      
    
        return ( ( vertex*(vertex-1))/2 == edge/2 );
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {

        unordered_map<int,list<int>> adj;

        for (int i = 0; i < n; i++) {
            adj[i] = {};
        }

        for (auto& it : edges) {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n, false);
        int ans = 0;
        for (int i = 0; i < n; i++) {
                if (!visited[i])
               { 
                 int val = solve(i, adj, visited);
                    ans+=val;
               }
        }
        return ans;
    }
};

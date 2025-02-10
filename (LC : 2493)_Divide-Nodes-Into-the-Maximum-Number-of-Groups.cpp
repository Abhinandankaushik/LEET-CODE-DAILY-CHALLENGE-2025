class Solution {
public:
    bool isBipart(unordered_map<int, vector<int>>& adj, vector<int>& bp, int i,
                  int color) {

        bp[i] = color;

        for (auto& it : adj[i]) {

            if (bp[it] == color)
                return false;

            if (bp[it] == -1) {
                int nColor = 1 - color;
                if (!isBipart(adj, bp, it, nColor))
                    return false;
            }
        }
        return true;
    }
   
    int BFS(int src, unordered_map<int, vector<int>>& adj,
            int n) {
       vector<bool>visited(n,false); //O(V+E)
        visited[src] = true;

        queue<int> q;
        q.push(src);
        int groupCount = 0;
        while (!q.empty()) {

            int size = q.size();

            for (int i = 0; i < size; i++) {

                auto front = q.front();
                q.pop();

                for (auto& it : adj[front]) {

                    if (!visited[it]) {
                        visited[it] = true;
                        q.push(it);
                    }
                }
            }
            groupCount++;
        }
      
        return groupCount;
    }

    int getMaxGroup(int src , unordered_map<int, vector<int>>& adj , vector<int>& maxG , vector<bool>& visited){
      
       int  maxi = maxG[src];
        visited[src] = true;
 
                for (auto& it : adj[src]) {
                    if (!visited[it]) {
                         maxi = max(maxi,getMaxGroup(it,adj,maxG,visited));
                        visited[it] = true;
                    }
                }
        return maxi;
            
        }
    int magnificentSets(int n, vector<vector<int>>& edges) {

        unordered_map<int, vector<int>> adj;
        for (int i = 0 ;i < edges.size() ;i++) {

            int u = edges[i][0] - 1;
            int v = edges[i][1] - 1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> bp(n, -1);
     
       //O(N*(V+E))
        for (int i = 0; i < n; i++) {//O(n)

            if (bp[i] == -1) {

                if (!isBipart(adj, bp, i, 1)) { //O(V+E)
                    return -1;
                }
            }
        }
       
       vector<int> maxG(n,0);
  
    for(int i = 0 ; i < n ; i++){//O(V+E)
         maxG[i]= BFS(i,adj,n);    
    }
      
      int maxGroup = 0;
      
      vector<bool>visited(n,false); //O(V+E)
      for(int i = 0 ;i < n ;i++){//O(V+E)
        if(!visited[i]){
             maxGroup += getMaxGroup(i,adj, maxG,visited);
        }
      }
      return maxGroup;

      }
};

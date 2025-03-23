class Solution {
public:
 typedef pair<long long ,int>P;

    int countPaths(int n, vector<vector<int>>& roads) {
        
        unordered_map<int,vector<pair<int,int>>>adj;

        for(auto& it : roads){
            int u = it[0];
            int v = it[1];
            int t = it[2];

            adj[u].push_back({v,t});
            adj[v].push_back({u,t});
        }

      int mod = 1e9+7;
        priority_queue<P,vector<P>,greater<P>>pq;

        vector<long long> result(n,LLONG_MAX);
        vector<long long> pathCount(n,0);

        result[0] = 1LL*0;
        pathCount[0] = 1LL*1;

        pq.push({0,0});

        while(!pq.empty()){

            auto front = pq.top();
            pq.pop();
            int u = front.second;
            long long  currentT = front.first;
             
            for(auto& it : adj[u]){

                int v = it.first;
                long long t = it.second;

                if( t + currentT < result[v]){

                    result[v] = t + currentT;
                    cout<< pathCount[v] <<" "<<pathCount[u]<<endl;
                    pathCount[v] = pathCount[u];
                    pq.push({result[v],v});

                }
                else if ( t + currentT ==  result[v] ){
                    cout<<(pathCount[v] + pathCount[u])%mod<<endl;
                     pathCount[v] = (pathCount[v] + pathCount[u])%mod;
                }
            } 

        }
      cout<<pathCount[n-1]<<endl;
        return pathCount[n-1];
    }
};


class Solution {
public:

     vector<int>parent;
     int find(int x){
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
     }

     void Union(int x , int y){
        parent[y] = x;
     }

    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        
        vector<int>cost(n);
        parent.resize(n);
        for(int i = 0 ;i < n ;i++){
            parent[i] = i;
            cost[i] = -1;
        }


        for(auto& edge : edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            int parent_u = find(u);
            int parent_v = find(v);

            if(parent_u != parent_v){

                Union(parent_u,parent_v);
                cost[parent_u] &= cost[parent_v];
            }

            cost[parent_u] &= w;
        }

         vector<int>result;
        for(auto &it : query){
             
             int start = it[0];
             int end = it[1];

             int parent_u = find(start);
             int parent_v = find(end);

             if(parent_u != parent_v){
                result.push_back(-1);
             }
             else{
                result.push_back(cost[parent_u]);
             }
        }

        return result;

    }
};

class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
       
       
          int n = recipes.size();
        unordered_map<string,list<int>> adj;
        vector<string>ans;
        unordered_set<string> st(supplies.begin(),supplies.end());
         vector<int>indegree(n,0);

        for(int i = 0 ; i < n ;i++){

             for(auto& it : ingredients[i]){

                 if(!st.count(it)){
                    adj[it].push_back(i);
                    indegree[i]++;
                 }
             }

        }

        queue<int>q;

        for(int i = 0 ;i < n ;i++){
             if(indegree[i] == 0)
             q.push(i);
        }

        while(!q.empty()){
             
             int i = q.front();
             q.pop();

             string rec = recipes[i];
              ans.push_back(rec);

              for(int &index : adj[rec]){

                indegree[index]--;
                if(indegree[index] == 0)
                q.push(index);

              }
        }
        return ans;
    }
};

class Solution {
public:
    vector<vector<int>> dr = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {

        int m = grid.size();
        int n = grid[0].size();

        
        vector<pair<int,int>>sortedQ;

        for (int i = 0; i < queries.size(); i++) {
           sortedQ.push_back({queries[i],i});
        }
        sort(sortedQ.begin(),sortedQ.end());


        vector<vector<bool>> visited(m, vector<bool>(n, false));
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        pq.push({grid[0][0], 0, 0});
        visited[0][0] = true;

        sort(queries.begin(), queries.end());

        vector<int> ans(queries.size(), 0);

        int count = 0;
        for (int j = 0; j < queries.size(); j++) {

            int val = sortedQ[j].first;
             int index = sortedQ[j].second;    
            while (!pq.empty() && pq.top()[0] < val) {

                int row = pq.top()[1];
                int col = pq.top()[2];
                pq.pop();
                count++;

                for (int i = 0; i < 4; i++) {

                    int n_r = row + dr[i][0];
                    int n_c = col + dr[i][1];

                    if (n_r < m && n_r >= 0 && n_c < n && n_c >= 0 && !visited[n_r][n_c]) {
                        pq.push({grid[n_r][n_c], n_r, n_c});
                        visited[n_r][n_c] = true;
                    }
                }
            }

            ans[index] = count;
        }

        return ans;
    }
};

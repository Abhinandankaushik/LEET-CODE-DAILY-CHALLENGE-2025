class Solution {
public:
    unordered_map<int, int> map; //<unique id, level>>
    vector<int> x = {-1, 1, 0, 0};
    vector<int> y = {0, 0, 1, -1};
    int lMax = INT_MIN;
    void BFS(int r, int c, vector<vector<bool>>& visited,
        vector<vector<int>>& grid, int& level) {
        int row = grid.size();
        int col = grid[0].size();
        visited[r][c] = true;
        grid[r][c] = level;
        queue<pair<int, int>> q;
        q.push({r, c});
        int count = 1;
        while (!q.empty()) {
            auto front = q.front();
            q.pop();
            int c_r = front.first;
            int c_c = front.second;
            for (int i = 0; i < 4; i++) {
                int n_r = c_r + x[i];
                int n_c = c_c + y[i];
                if (n_r >= 0 && n_r < row && n_c >= 0 && n_c < col &&
                    !visited[n_r][n_c] && grid[n_r][n_c] != 0) {
                    visited[n_r][n_c] = true;
                    q.push({n_r, n_c});
                    grid[n_r][n_c] = level;
                    count++;
                }
            }
        
        map[level] = count;
        lMax = max(lMax, level);
    }
        }
    int largestIsland(vector<vector<int>>& grid) {

        int row = grid.size();
        int col = grid[0].size();

        vector<vector<bool>> visited(row, vector<bool>(col, false));
        int level = 2;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    BFS(i, j, visited, grid, level);
                    level++;
                }
            }
        }
        int maxIsland = INT_MIN;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {

                if (grid[i][j] == 0 && !visited[i][j]) {

                    set<int> st;
                    for (int k = 0; k < 4; k++) {
                        int n_r = i + x[k];
                        int n_c = j + y[k];
                        if (n_r >= 0 && n_r < row && n_c >= 0 && n_c < col &&
                            grid[n_r][n_c] != 0) {
                            st.insert(grid[n_r][n_c]);
                        }
                    }
                    int tempAns = 0;
                    while (!st.empty()) {
                        tempAns += map[*st.begin()];
                        st.erase(*st.begin());
                    }
                    maxIsland = max(maxIsland, tempAns);
                }
            }
        }
        return maxIsland == INT_MIN ? map[lMax] : maxIsland + 1;
    }
};

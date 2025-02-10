class Solution {
public:
    // for bound checking && already visited
    bool isSafe(int r, int c, int row, int col, vector<vector<int>>& grid,
                vector<vector<bool>>& visited) {
        return (r >= 0 && r < row && c >= 0 && c < col && grid[r][c] != 0 &&
                !visited[r][c]);
    }

    // direction vector
    vector<int> X = {-1, 1, 0, 0};
    vector<int> Y = {0, 0, -1, 1};

    // storing maximum ans
    int maxAns = 0;

    // doing BFS for all adjacent fish tank
    void BFS(int srcX, int srcY, vector<vector<int>>& grid,
             vector<vector<bool>>& visited) {
                int row = grid.size();
                int col = grid[0].size();
        visited[srcX][srcY] = true;
        queue<pair<int, int>> q;
        q.push({srcX, srcY});
        int temp = 0;
        while (!q.empty()) {

            auto front = q.front();
            q.pop();
            int r = front.first;
            int c = front.second;
            temp += grid[r][c];
            for (int i = 0; i < 4; i++) {

                int n_r = r + X[i];
                int n_c = c + Y[i];
                if (isSafe(n_r, n_c, row, col, grid, visited)) {
                    visited[n_r][n_c] = true;
                    q.push({n_r, n_c});
                }
            }
        }
        maxAns = max(maxAns,temp);
    }

    int findMaxFish(vector<vector<int>>& grid) {

        int row = grid.size();
        int col = grid[0].size();

        vector<vector<bool>> visited(row, vector<bool>(col, false));

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {

                if (!visited[i][j] && grid[i][j] != 0) {

                    BFS(i, j,grid, visited);
                }
            }
        }
        return maxAns;
    }
};

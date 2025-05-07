class Node {
public:
    int row;
    int col;
    int cost;
    Node(int row, int col, int cost) : row(row), col(col), cost(cost) {}
};

class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveCost) {
       
        int INF = 0x3f3f3f3f;
        int rows = moveCost.size(), cols = moveCost[0].size();
        vector<vector<int>> minTime(rows, vector<int>(cols, INF));
        vector<vector<int>> visited(rows, vector<int>(cols, 0));

        int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        minTime[0][0] = 0;

        auto compare = [](const Node& a, const Node& b) { return a.cost > b.cost; };
        priority_queue<Node, vector<Node>, decltype(compare)> pq(compare);
        pq.push(Node(0, 0, 0));

        while (!pq.empty()) {
            Node current = pq.top();
            pq.pop();
            if (visited[current.row][current.col]) continue;
            visited[current.row][current.col] = 1;

            for (int dir = 0; dir < 4; dir++) {
                int newRow = current.row + directions[dir][0];
                int newCol = current.col + directions[dir][1];
                if (newRow < 0 || newRow >= rows || newCol < 0 || newCol >= cols) continue;

                int newCost = max(minTime[current.row][current.col], moveCost[newRow][newCol]) + 1;
                if (minTime[newRow][newCol] > newCost) {
                    minTime[newRow][newCol] = newCost;
                    pq.push(Node(newRow, newCol, newCost));
                }
            }
        }

        return minTime[rows - 1][cols - 1];
    }
};

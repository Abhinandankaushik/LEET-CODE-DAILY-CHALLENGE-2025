class DSU {
public:
    vector<int> parent;
    vector<int> rank;
    DSU(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
            rank[i] = 1;
        }
    }

    int find(int x) {
        if (x == parent[x]) {
            return x;
        }

        int x_parent = find(parent[x]);
        parent[x] = x_parent;
        return x_parent;
    }

    void Union(int x, int y) {

        int x_parent = find(x);
        int y_parent = find(y);

        if (x_parent == y_parent) {
            return;
        }

        if (rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        } else if (rank[y_parent] > rank[x_parent]) {
            parent[x_parent] = y_parent;
        } else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU s(n);

        for (auto it : edges) {

            int x = it[0];
            int y = it[1];
            int x_parent = s.find(x);
            int y_parent = s.find(y);
            if (x_parent == y_parent) {
                return {x, y};
            } else
               {
                 s.Union(x, y);
                 }
        }
        return {};
    }
};

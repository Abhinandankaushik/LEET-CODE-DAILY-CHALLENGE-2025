class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {

        int n = queries.size();
        vector<int> ans(n);
        unordered_map<int, int> balls; //S.C : O(n)
        unordered_map<int, int> colors;

        for (int i = 0; i < n; i++) { // T.C : O(n)

            int at = queries[i][0];
            int color = queries[i][1];

            if (balls.find(at) != balls.end()) {

                int prevColor = balls[at];
                colors[prevColor]--;
                if (colors[prevColor] == 0) {
                    colors.erase(prevColor);
                }
                balls[at] = color;
                colors[color]++;
            } else {
                balls[at] = color;
                colors[color]++;
            }

            ans[i] = colors.size();
        }
        return ans;
    }
};

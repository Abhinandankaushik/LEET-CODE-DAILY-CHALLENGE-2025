class Solution {
public:
    bool solve(int n, int index, vector<int>& ans, vector<bool>& used) { 

        if (index >= ans.size())
            return true;

        if (ans[index] != -1)
            return solve(n, index + 1, ans, used);

        for (int i = n; i >= 1; i--) { //T.C : O(n!)

            if (used[i])
                continue;

            used[i] = true;
            ans[index] = i;

            if (ans[index] == 1) {

                if (solve(n, index + 1, ans, used)) {
                    return true;
                }

            } else {

                int j = index + i;

                if (j < ans.size() && ans[j] == -1) {
                    ans[j] = i;
                    if (solve(n, index + 1, ans, used))
                        return true;

                    ans[j] = -1;
                }
            }
            used[i] = false;
            ans[index] = -1;
        }
        return false;
    }
    vector<int> constructDistancedSequence(int n) {
        vector<int> ans(2 * n - 1, -1); //S.C : O(n)
        vector<bool> used(2 * n - 1, false);
        solve(n, 0, ans, used);
        return ans;
    }
};

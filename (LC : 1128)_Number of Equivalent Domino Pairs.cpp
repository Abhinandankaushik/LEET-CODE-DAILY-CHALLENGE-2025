class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {

        map<pair<int, int>, int> mp; //S.C :O(n)

        for (auto& it : dominoes) {  //T.C : O(n*log(n))
            sort(it.begin(), it.end());
            int a = it[0];
            int b = it[1];
            mp[{a, b}]++;
        }

        int ans = 0;
        for (auto& it : mp) {
            int count = it.second;
            ans += (count * (count - 1)) / 2;
        }

        return ans;
    }
};

class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words,
                                         vector<int>& groups) {

        vector<string> ans;
        int n = groups.size();
        ans.push_back(words[0]);
        int temp = groups[0];
        for (int i = 1; i < n; i++) { //T.C : O(n) , S.C : O(n)

            if (temp != groups[i]) {
                ans.push_back(words[i]);
                temp = groups[i];
            }
        }
        return ans;
    }
};

class Solution {
public:
    string makeFancyString(string s) {

        int c = 0;
        int n = s.length();
        string ans;
        ans.push_back(s[0]);
        for (int i = 1; i < n; i++) {

            if (s[i] == s[i - 1] && c < 1) {
                ans.push_back(s[i]);
                c++;
            } else if (s[i] != s[i-1]) {
                ans.push_back(s[i]);
                c = 0;
            }
        }
        return ans;
    }
};

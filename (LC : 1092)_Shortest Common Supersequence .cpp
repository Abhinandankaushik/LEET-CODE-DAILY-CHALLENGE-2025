class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {

        int m = str1.length();
        int n = str2.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // compute all length of SCSS in dp grid
        for (int i = 0; i < m + 1; i++) {

            for (int j = 0; j < n + 1; j++) {

                if (i == 0 || j == 0) {
                    dp[i][j] = i + j;
                } else if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = 1 + min(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }

        int i = m, j = n;
        string ans = "";
        // each row index / column index represent a sequence of characters
        // where the SCSS
        // in grid is calculated compare ending index-1 character and calculate
        // the answer
        while (i > 0 && j > 0) {

            if (str1[i - 1] == str2[j - 1]) {
                ans.push_back(str1[i - 1]);
                i--;
                j--;
            } else if (dp[i - 1][j] < dp[i][j - 1]) {

                ans.push_back(str1[i - 1]);
                i--;
            } else {
                ans.push_back(str2[j - 1]);
                j--;
            }
        }
      
       // if one string is end and other is still left append all charachter on it to the ans stirng 
        while (i > 0) {
            ans.push_back(str1[i - 1]);
            i--;
        }

        while (j > 0) {
            ans.push_back(str2[j - 1]);
            j--;
        }
        
        //reverse the ans string 
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

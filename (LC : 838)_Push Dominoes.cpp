class Solution {
public:
    string pushDominoes(string dominoes) {

        int n = dominoes.length();

        vector<int> left(n, -1);  //S.C : O(n)
        vector<int> right(n, -1);

        for (int i = 0; i < n; i++) { //T.C : O(n)

            if (dominoes[i] == 'R') {
                right[i] = i;
            } else if (dominoes[i] == '.' && i - 1 >= 0) {
                right[i] = right[i - 1];
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            if (dominoes[i] == 'L') {
                left[i] = i;
            } else if (dominoes[i] == '.' && i + 1 < n) {
                left[i] = left[i + 1];
            }
        }

        string ans(n, '.');
        for (int i = 0; i < left.size(); i++) {

            int leftI = left[i];
            int rightI = right[i];

            if (leftI == -1 && rightI != -1)
                ans[i] = 'R';
            else if (leftI != -1 && rightI == -1)
                ans[i] = 'L';
            else if (leftI != -1 && rightI != -1) {

                leftI = abs(leftI - i);
                rightI = abs(rightI - i);

                if (leftI < rightI)
                    ans[i] = 'L';
                else if (leftI > rightI)
                    ans[i] = 'R';
            }
        }
        return ans;
    }
};

class Solution {
public:
    string solve(string s) {

        int n = s.length();
        char ch = s[n - 1];
        int count = 0;
        string temp;
        for (int index = n - 1; index >= 0; index--) {

            if (ch == s[index]) {
                count++;
            } else {
                temp.push_back(ch);
                temp.push_back((count + '0'));
                ch = s[index];
                count = 1;
            }
        }
        temp.push_back(ch);
        temp.push_back((count + '0'));
        reverse(temp.begin(), temp.end());
        return temp;
    }
    string countAndSay(int n) {

        string s = "1";
        for (int i = 1; i < n; i++) { //T.C : O(n*n)  , S.C : O(n)
            s = solve(s);
        }

        return s;
    }
};

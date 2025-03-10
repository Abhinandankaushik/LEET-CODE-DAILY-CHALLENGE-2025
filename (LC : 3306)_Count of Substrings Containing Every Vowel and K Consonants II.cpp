class Solution {
public:
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'i' || ch == 'e' || ch == 'o' || ch == 'u';
    }

    long long countOfSubstrings(string word, int k) {

        int n = word.length();
        if (n < 5)
        return 0;

        vector<int> nextConst(n); //S.C : O(n)
        int lastConst = n;
        for (int i = n - 1; i >= 0; i--) { //T.C : O(n)
            char ch = word[i];
            nextConst[i] = lastConst;
            if (!isVowel(ch)) {
                lastConst = i;
            }
        }

        int i = 0;
        int j = 0;
        long long ans = 0;
        int count = 0;
        unordered_map<char, int> mp;//S.C : O(5) {constant}
        while (j < n) { //T.C : O(n)

            char ch = word[j];

            if (isVowel(ch)) {
                mp[ch]++;
            } else {
                count++;
            }

            while (i < n && count > k) {

                char c = word[i];
                if (isVowel(c)) {
                    mp[c]--;
                    if (mp[c] == 0) {
                        mp.erase(c);
                    }
                } else {
                    count--;
                }
                 i++;
            }

            while (i < n && mp.size() == 5 && count == k) {
                ans += (nextConst[j] - j);

                char front = word[i];
                if (isVowel(front)) {
                    mp[front]--;
                    if (mp[front] == 0) {
                        mp.erase(front);
                    }
                } else {
                    count--;
                }

                i++;
            }
            j++;
        }
        return ans;
    }
};

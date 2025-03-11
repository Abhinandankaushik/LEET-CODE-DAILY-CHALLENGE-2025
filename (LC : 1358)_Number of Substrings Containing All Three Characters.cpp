
class Solution {
public:
    bool isOkay(vector<int>& freq) {
        return freq[0] > 0 && freq[1] > 0 && freq[2] > 0;
    }
    int numberOfSubstrings(string s) {

        int n = s.length();
        int i = 0, j = 0;
        int ans = 0;

        vector<int> freq(3, 0); //S.C : O(3) --> constant
        
        while (j < n) { //T.C : O(n)
            char ch = s[j];

            freq[ch - 'a']++;

            while (isOkay(freq)) {
                ans += (n - j);
                freq[s[i] - 'a']--;
                i++;
            }
            j++;
        }
        return ans;
    }
};

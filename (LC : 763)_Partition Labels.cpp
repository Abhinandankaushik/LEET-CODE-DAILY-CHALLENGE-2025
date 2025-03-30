class Solution {
public:
    vector<int> partitionLabels(string s) {

        unordered_map<char, int> mp; //S.C : O(K) //k==26 --> constant --> O(1)

        for (int i = 0; i < s.length(); i++) { //T.C : O(n)
            mp[s[i]] = i;
        }

        int last = 0;
        int prev = 0;
        vector<int> ans;

        for (int i = 0; i < s.length(); i++) { //T.C : O(n)

            last = max(last, mp[s[i]]);
            if (last <= i) {
                ans.push_back((i + 1) - prev);
                prev = i + 1;
            }
        }

        return ans;
    }
};

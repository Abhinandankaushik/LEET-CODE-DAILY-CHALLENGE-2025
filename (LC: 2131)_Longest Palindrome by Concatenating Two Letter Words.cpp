class Solution {
public:
    int longestPalindrome(vector<string>& words) {

       map<string, int> mp;  //S.C : O(n)

        int count = 0;
        for (auto& it : words) { //T.C : O(n*log(n))

            string temp = it;

            reverse(temp.begin(), temp.end());

            if (mp.find(temp) != mp.end()) {

                count += 4;

                mp[temp]--;
                if (mp[temp] == 0) {
                    mp.erase(temp);
                }

            } else {
                mp[it]++;
            }
        }

        bool isSame = true;
        for (auto& it : mp) {

            if (it.second > 1 && it.first[0] == it.first[1]) {
                count += (it.second * 2);
                mp.erase(it.first);
            } else if (isSame && it.first[0] == it.first[1]) {
                count += 2;
                isSame = 0;
            }
        }

        return count;
    }
};

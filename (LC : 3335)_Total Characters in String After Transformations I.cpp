
class Solution {
public:
    int lengthAfterTransformations(string s, int t) {

       vector<int>v(26);
        for (auto& it : s) { //T.C : O(n)
            v[it-'a']++;
        }
        int mod = 1e9 + 7;
         

        for (int i = 0; i < t; i++) { //T.C : O(t)

               vector<int>temp(26,0);

            for (int j = 0 ; j < 26 ; j++) { //T.C : O(26)
              
                int freq = v[j];

                if (j+1 != 26) {
                    temp[j+1] = (temp[j + 1] + freq) % mod;

                } else {
                    temp[0] = (temp[0] + freq) % mod;
                    temp[1] = (temp[1] + freq) % mod;
                }
            }

            v = move(temp);
        }

        int ans = 0;
        for (auto& it : v) {
            ans = (ans + it ) % mod;
        }
        return ans;
    }
};

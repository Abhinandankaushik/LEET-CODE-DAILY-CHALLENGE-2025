class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {

        int n = colors.size();
        int alternate = 1;
        int last = 0;  //S.C : O(1)
        int ans = 0;                  
        for (int i = 1; i < n + k - 1; i++) { //T.C : O(n+k) 
 
            int index = i % n;

            if (colors[index] == colors[last]) {
    //color matched so till this index no grouped with alternate color possible 
                alternate = 1;
            } else {
                alternate++;
            }

            last = index;

            if (alternate >= k) {
                ans++;
            }
        }
        return ans;
    }
};

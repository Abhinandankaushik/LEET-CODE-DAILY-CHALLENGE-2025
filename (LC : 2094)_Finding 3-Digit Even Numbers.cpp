class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {

        int n = digits.size();
        set<int> st;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {

                    int num = (digits[i] * 100 + digits[j] * 10 + digits[k]);
                    if (!(num & 1) && num / 100 && (j != k) &&
                        (i != j && i != k)) {
                        st.insert(num);
                    }
                }
            }
        }

        vector<int> ans(st.begin(), st.end());
        return ans;
    }
};

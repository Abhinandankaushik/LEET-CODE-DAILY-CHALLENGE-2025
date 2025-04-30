class Solution {
public:
    int findNumbers(vector<int>& nums) {

        int n = nums.size();
        int ans = 0;
        for (auto& it : nums) {//T.C : O(n*log(n))  &  S.C : O(1)

            int num = it;
            int count = 0;
            while (num) {

                count++;
                num /= 10;
            }

            ans += (count & 1 ? 0 : 1);
        }
        return ans;
    }
};

class Solution {
public:
    // T.C : O(10) --> constant
    int number_to_digit(int n) {

        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n = n / 10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {

        // maximum digit sum = 9+9+9+9+9+9+9+9+9 = 81
        vector<int> mp(82, INT_MIN); // S.C : O(82) --> constant(1)

        int result = INT_MIN;
        for (int i = 0; i < nums.size(); i++) { // T.C : O(n)

            int digit = number_to_digit(nums[i]);

            if (mp[digit] != INT_MIN) {

                result = max(result, mp[digit] + nums[i]);
                mp[digit] = max(mp[digit], nums[i]);
            } else {
                mp[digit] = nums[i];
            }
        }

        return result == INT_MIN ? -1 : result;
    }
};

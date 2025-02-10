class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {

        int n = nums.size();
        bool isOdd = nums[0] % 2;
        for (int i = 1; i < n; i++) {

            if (isOdd == nums[i] % 2) {
                return false;
            }
            isOdd = nums[i] % 2;
        }
        return true;
    }
};

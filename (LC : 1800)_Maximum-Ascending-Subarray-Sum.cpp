class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {

        int maxSum = INT_MIN;
        int n = nums.size();
        int temp = 0;
        for (int i = 0; i < n - 1; i++) {

            if (nums[i] < nums[i + 1]) {
                temp += nums[i];
            } else {
                temp += nums[i];
                maxSum = max(maxSum, temp);
                temp = 0;
            }
        }
        temp += nums[n - 1];
        maxSum = max(maxSum, temp);
        return maxSum;
    }
};

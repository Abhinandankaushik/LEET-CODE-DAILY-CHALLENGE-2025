class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {

        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {

            ans = max(ans, (abs(nums[i % n] - nums[(i + 1) % n])));
        }
        return ans;
    }
};

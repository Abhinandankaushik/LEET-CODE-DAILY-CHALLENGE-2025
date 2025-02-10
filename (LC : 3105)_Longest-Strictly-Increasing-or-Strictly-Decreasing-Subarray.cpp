class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {

        int n = nums.size();

        int inc = 1;

        int temp = 1;
        for (int i = 1; i < n; i++) {

            if (nums[i] > nums[i - 1]) {
                temp++;
            } else {
                inc = max(inc, temp);
                temp = 1;
            }
        }
        inc = max(inc, temp);
        int dic = 1;
        temp = 1;
        for (int i = 1; i < n; i++) {

            if (nums[i] < nums[i - 1]) {
                temp++;
            } else {
                dic = max(dic, temp);
                temp = 1;
            }
        }
        dic = max(dic, temp);
        return max(inc, dic);
    }
};

class Solution {
public:
    int left(vector<int>& nums, int index, int n, int target) {

        int l = index + 1;
        int e = n - 1;
        int ans = -1;
        while (l <= e) {

            int mid = (l + e) / 2;
            if (nums[mid] >= target) {
                ans = mid;
                e = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }

    int right(vector<int>& nums, int index, int n, int target) {

        int l = index + 1;
        int e = n - 1;
        int ans = -1;
        while (l <= e) {

            int mid = (l + e) / 2;
            if (nums[mid] <= target) {
                ans = mid;
                l = mid + 1;
            } else {
                e = mid - 1;
            }
        }
        return ans;
    }

    long long countFairPairs(vector<int>& nums, int lower, int upper) {

        sort(nums.begin(), nums.end());

        int n = nums.size();

        long long ans = 0;
        for (int i = 0; i < n; i++) {  //T.C : O(n*log(n))   //S.C : O(log(n))
            int x = nums[i];
            int n_l = lower - x;
            int n_e = upper - x;

            int leftval = left(nums, i, n, n_l);
            int rightval = right(nums, i, n, n_e);

            if (leftval != -1 && rightval != -1) {
                ans += (rightval-leftval+1);
            }
        }

        return ans;
    }
};

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {

        int n = nums.size();
        unordered_map<long long, int> map;
        // finding all 2 paired products
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                long long multi = nums[i] * nums[j];
                map[multi]++;
            }
        }

        int ans = 0;
        for (auto& it : map) {
            if (it.second >= 2) {
                int total_group = it.second;
                // 2+2 pair product = 4 touple --> n*(n-1)/2
                int touple = (total_group * (total_group - 1)) / 2;
                ans += touple * 8;
            }
        }
        return ans;
    }
};

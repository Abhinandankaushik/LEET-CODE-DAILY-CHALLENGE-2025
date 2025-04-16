class Solution {
public:
    long long countGood(vector<int>& nums, int k) {

        int i = 0, j = 0;

        unordered_map<int, int> mp;
        int n = nums.size();
        int pair = 0;
        long long ans = 0;
        while (j < n) {

            int val = nums[j];
            pair += mp[val];
            mp[val]++;

            while(pair >= k){
                ans += (n-j);
                mp[nums[i]]--;
                pair -= mp[nums[i]];
                i++;
            }
            j++;
        }

        return ans;
    }
};

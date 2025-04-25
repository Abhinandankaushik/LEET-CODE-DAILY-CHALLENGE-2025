class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {

        int n = nums.size();

        map<int, int> mp; //S.C : O(n)
        long long ans = 0;
        mp[0]=1;
        long long sum = 0;
        for (int i = 0; i < n; i++) { //T.C : O(n*log(n))
            sum += (nums[i] % modulo == k ? 1 : 0);
            long long r1 = sum%modulo; 
            long long r2 = (r1 - k + modulo)%modulo;
            ans += mp[r2];
            mp[r1]++;
        }
        return ans;
    }
};

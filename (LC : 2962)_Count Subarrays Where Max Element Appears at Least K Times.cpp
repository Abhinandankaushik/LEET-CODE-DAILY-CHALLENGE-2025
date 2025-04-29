class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {

        int maxi = *max_element(nums.begin(), nums.end()); //T.C : O(n)
        long long ans = 0;

        int n = nums.size();
        int i = 0;
        int j = 0;
        int count = 0;
        while (j < n) {  //T.C : O(n) , S.C : O(1)

            if (nums[j] == maxi) {
                count++;
            }
            while (count >= k) {

                ans += (n - j);
                if (nums[i] == maxi) {
                    count--;
                }
                i++;
            }

            j++;
        }
        return ans;
    }
};

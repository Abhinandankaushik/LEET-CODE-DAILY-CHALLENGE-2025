class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {

        int i = 0, j = 0;
        int n = nums.size();
        map<int, int> mp;
        int sum = 0;
        int ans = INT_MIN;
        while (j < n) {  //T.C : O(n)
            sum += nums[j]; 
            mp[nums[j]]++;
           

                while (i <= j && mp[nums[j]] > 1) {
                    sum -= nums[i];
                    mp[nums[i]]--;
                    if (mp[nums[i]] == 0) {
                        mp.erase(nums[i]);
                    }

                    i++;
                }
           
           ans = max(ans,sum);

           
            j++;
        }
        return ans ;
    }
};

class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        
        int n = nums.size();

        for(int i = 0 ;i < n;i++){ //T.C : O(n) , S.C : O(1)
           
            int val  = nums[nums[i]]%n;
            nums[i] = val*n + nums[i];

        }

        for(auto &it : nums){
            it /= n;
        }
        return nums;
    }
};

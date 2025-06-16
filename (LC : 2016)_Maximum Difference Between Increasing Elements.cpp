class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        
        int maxi =-1;
        int mini = nums[0];
          int n = nums.size();
        for(int i = 1 ;i < n;i++){ //T.C : O(n)

               if(nums[i] > mini)  
              maxi =  max(maxi,nums[i]-mini);

              mini = min(mini,nums[i]);
        }

        return maxi;
    }
};

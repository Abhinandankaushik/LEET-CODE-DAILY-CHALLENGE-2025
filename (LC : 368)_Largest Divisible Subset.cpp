class Solution {
public:
    vector<int> solve(vector<int>&nums){
         int n = nums.size();
        vector<int>dp(n,1);
        vector<int>prev(n,-1);
        vector<int>ans;
         int maxlen = 0;        
         int maxi = 0;
       for(int i = 1 ; i <  n ;i++){

         for(int j = 0 ; j < i ;j++){

             if(nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]){
                dp[i] = dp[j] + 1;
                prev[i] = j ;
             }  
              if(dp[i] > maxlen){
                maxlen = dp[i];
                maxi = i;
              }
         }
       }

       while(maxi != -1){
        ans.push_back(nums[maxi]);
        maxi = prev[maxi];
       }
       
    return ans;
        

    }

    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        return solve(nums);

    }
};

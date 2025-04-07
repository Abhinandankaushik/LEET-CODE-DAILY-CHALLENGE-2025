class Solution {
public:  
   
  
   //Tabulation Method  
      bool solve(vector<int>& nums){
        
          int n = nums.size();

         int sum = accumulate(begin(nums),end(nums),0);
           if(sum%2 != 0) return false;
            sum/= 2;
             

        vector<vector<bool>>dp(sum+1,vector<bool>(n+1,false));
            
            
           for(int i = 0 ;i <= n ;i++)
         {     dp[0][i] = true;}
          

          for(int j =  1 ; j <= sum ; j++ ){
               
                for(int i = n-1 ; i >= 0 ;i--){
                   
            bool inc  = j-nums[i] < 0 ? false : dp[j - nums[i]][i + 1];
            bool exc = dp[j][i+1];

            dp[j][i] = ( inc||exc);
             

                }
          }
         
         return dp[sum][0];
  
   }

    bool canPartition(vector<int>& nums) {

     return solve(nums);

    }
};

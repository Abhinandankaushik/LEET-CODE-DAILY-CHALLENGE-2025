class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<int>leftMax(n,0);  //S.C : O(n)
        vector<int>rightMax(n,0); 

        leftMax[0] = nums[0];
        for(int i = 1 ;i < n;i++) { //T.C : O(n)
             leftMax[i] = max(leftMax[i-1] , nums[i]);
        } 

        rightMax[n-1] = nums[n-1];
        for(int i = n-2; i >= 0 ; i--){
            rightMax[i] = max(rightMax[i+1],nums[i]);
       }


       long long ans = 0;

       for(int i = 1 ;i < n-1 ;i++){
           long long curSum = 1LL*(leftMax[i-1] - nums[i])*rightMax[i+1];
           ans  = max(ans,curSum);
       }

     return ans;

    }
};

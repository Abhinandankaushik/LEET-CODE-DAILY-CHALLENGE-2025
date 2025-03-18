class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {

        int n = nums.size();

        int i = 0, j = 0;
        int ans = 0;
        int val = 0 ;

     while (j < n) {   //T.C : O(n)
            
        while( i <= j && ( val & nums[j] )  > 0 ){
            val^=nums[i];
             i++;
          }

          val = (val | nums[j]);
          ans = max(ans,j-i+1);
       
          j++;
        }
     
     
        return ans ;
    }
};

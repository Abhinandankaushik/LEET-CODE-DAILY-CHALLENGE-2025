class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        // Double check kadein's Algorithm
        int n = nums.size();
        
        //track minimum negatie value 
        int n_max = 0;   //S.C : O(1)
 
        //track maximum positive value
        int p_max = 0;

        int n_sum = 0;
        int p_sum = 0;
        
        for(int i = 0 ;i  < n ;i++){ //T.C : O(n)
            n_sum += nums[i];
            p_sum += nums[i];

            n_max = min(n_max,n_sum);
           //if current negative sum > 0 reset it to ->>0 
            if(n_sum > 0) {
                n_sum = 0;
            }

            p_max = max(p_max,p_sum);
            //if current positive sum < 0 reset it to --> 0
            if(p_sum < 0){
                p_sum = 0;
            }
        }
         //compair positive sum and absolute value of minimum negative value 
         // and return the max value 
        return p_max > abs(n_max) ? p_max : abs(n_max);
    }
};

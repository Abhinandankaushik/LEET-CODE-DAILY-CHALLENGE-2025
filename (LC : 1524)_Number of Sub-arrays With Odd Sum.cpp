class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {

        int n = arr.size();
         
         //calculate accumulative sum 
        vector<int> preSum(n, 0);
        preSum[0] = arr[0];

        for (int i = 1; i < n; i++) {
            preSum[i] = arr[i] + preSum[i - 1];
        }
        
        int mod = 1e9+7;
        int even_count = 0; 
        int odd_count = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
              
             //even + odd = odd 
            if (preSum[i] % 2 != 0) {
                ans += (even_count + 1)%mod;
                ans = (ans)%mod;
                odd_count++;
                continue;
            } 
            else {
                //odd + even = odd
                even_count++;
                ans += ( odd_count)%mod;
                ans = (ans)%mod;
            }
        }
        return ans;
    }
};

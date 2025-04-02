class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        
        long long ans = LONG_LONG_MIN;
       int n = nums.size();
        for(int i = 0 ; i < n;i++){ //T.C : O(n*n*n)
            for(int j = i + 1 ; j  < n ;j++){
                for(int k = j+1 ; k < n; k++){
                 long long val = 1LL*(nums[i]-nums[j])*nums[k];
                    ans = max(ans,val);
                }
            }
        }
        return ans > 0 ? ans : 0 ;
    }
};

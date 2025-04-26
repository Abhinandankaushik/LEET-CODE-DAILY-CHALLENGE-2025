class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        
        long long minp = -1;
        long long maxp = -1;
        long long invalid = -1;

        long long ans = 0;

        for(int i = 0 ; i < nums.size() ;i++){

            if(nums[i] < minK || nums[i] > maxK)
            invalid = i;

            if(nums[i] == minK ) 
            minp = i;


            if(nums[i] == maxK) 
            maxp = i;

            long long smaller = min(minp,maxp);
            long long temp = smaller - invalid;
            cout<<temp<<endl;
            ans += (temp <= 0 ) ? 0 : temp ;
        }
     
        return ans;
    }
};

class Solution {
public:
    int maxSum(vector<int>& nums) {
        
        set<int>st;
          
          int maxi = INT_MIN;
        for(int i = 0 ;i < nums.size() ;i++){

             if(nums[i] > 0){
                st.insert(nums[i]);
             }
             maxi = max(maxi,nums[i]);
        } 
        if(st.empty()) return maxi;
          
          int ans = 0;
        while(!st.empty()){
            ans+=*st.begin();
            st.erase(st.begin());
        }
        return ans;
    }
};

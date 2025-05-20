class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
         
         int n = nums.size();

         vector<int>v(n,0);   //S.C : O(n)
         for(auto& it : queries){ //T.C : O(n+q)
             int l = it[0];
             int r = it[1];
             v[l]--;
             if(r +1 < n){
                v[r+1]++;
             }
         }

         for(int i = 1 ;i < n;i++){
              v[i]+=v[i-1];
            if((nums[i-1]+v[i-1]) > 0) return false;
         }
          if((nums[n-1]+v[n-1]) > 0) return false;
         
         return true;
    }
};

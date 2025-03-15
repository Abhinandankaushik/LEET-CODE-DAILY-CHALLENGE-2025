class Solution {
public:
   
    bool isOkay(vector<int>&nums, int k ,int mid){  //T.C : O(n)
           
         int i = 0 ;

         while( i < nums.size() ){

              if(nums[i] <= mid){
                k--;
                i = i+2;
           continue;
              }
              i = i+1;
         }  

         return k <= 0 ;
    }
    int minCapability(vector<int>& nums, int k) {
        
        int n = nums.size();
        int s = *min_element(nums.begin(),nums.end());
        int l = *max_element(nums.begin(),nums.end());
        
        int ans = INT_MAX;
        while(s <= l ){  //T.C : O(log(n)) --> O[n*log(n)]
          
           int mid = (s+l)/2;

           if(isOkay(nums,k,mid)){
              ans = min(ans,mid);
              l = mid - 1;
           }
           else {
             s = mid+1;
           }

        }

        return ans;
    }
};

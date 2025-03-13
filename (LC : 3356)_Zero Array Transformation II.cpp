class Solution {
public: 
   
bool isOkay(vector<int>& nums, vector<vector<int>>& queries , int k ){
   int n = nums.size();
   vector<int>diffArr(n+1);
   int sum = 0;
     for(int i = 0 ; i < k ;i++){
          
          int s = queries[i][0];
          int e = queries[i][1];
          int val = queries[i][2];

          diffArr[s]  += val;
          diffArr[e+1] -= val;
     }

     for(int i = 0 ;i < n ;i++){
        sum += diffArr[i];
        if(sum < nums[i])return false;
     }
     return true;
   }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        
        int n = queries.size();
        
        //s = 0 beacuse it is possible without applying any queries array become zero array
        //means array all elements are already zero so there no need ant query that's why
        // s = 0 
        int s = 0 , l = n;

        //if after apply all queries nums will no transform into zero array return -1
        if(!isOkay(nums,queries,l)) return -1;  

        int ans = 0;
        while( s <= l){ //T.c : O[n*log(n)]
            int mid = (s+l)/2;

            if(isOkay(nums,queries,mid)){
                ans = mid ;
                l = mid -1;
            }
            else {
                s = mid+1;
            }
        }
         
        
        return ans;
    }
};

class Solution {
public: 
       
     bool isOkay(vector<int>& candies , int mid , long long k){ //T.C  : O(n)
      
          for(auto it : candies){
            k-=(it/mid);
          }
        return k <= 0 ;
     }


    int maximumCandies(vector<int>& candies, long long k) {
       int s = 1;
       int l = *max_element(candies.begin(),candies.end());
       int ans =  0;

       while(s <= l){  //T.C : O(logn) ==> O[ n*log(n)]

        int mid = (s+l)/2;

          if(isOkay(candies,mid,k)){
          
            ans = max(ans,mid);
            s = mid+1;
          }
          else {
            l = mid-1;
          }
       } 
       return ans;
    }
};

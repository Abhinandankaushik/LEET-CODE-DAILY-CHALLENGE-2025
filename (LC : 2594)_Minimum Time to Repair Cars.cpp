class Solution {
public: 
      
      bool isOkay(vector<int>& ranks , long long  k , long long  mid){ //T.C : O(n)
    
              long long totalCarRepaired = 0;
            for(auto it : ranks){
             totalCarRepaired+=sqrt(1.0*mid/it);
            }
            return k-totalCarRepaired <= 0;
      }

    long long repairCars(vector<int>& ranks, int cars) {
         
        long long  n = ranks.size();
        long long  s = 1;
        long long  l = 1LL*cars*cars*(*max_element(ranks.begin(),ranks.end())) ;
        long long  ans = LONG_MAX;
     
        while( s <= l){ //T.C : O(log(n))
           long long  mid = s+(l-s)/2;
            if(isOkay(ranks,cars,mid)){
                ans = min(ans,mid);
                l = mid-1 ;
            }
            else {
                s = mid+1;
            }
        }
        return ans;
    }
};
